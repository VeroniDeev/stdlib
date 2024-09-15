#include "stdio.h"
#include "sys.h"
#include "string.h"
#include "utils.h"
#include <stdarg.h>

int64_t open(const void* path_ptr, size_t len) {
	return syscall(2, (uint64_t) path_ptr, len, 0, 0);
}

int64_t close(uint32_t fd) {
	return syscall(5, fd, 0, 0, 0);
}

/// wrapper around open that takes a null-terminated path
int64_t open_n(const char* path) {
	size_t len = strlen(path);

	return open(path, len);
}

int64_t write(uint32_t fd, const void* ptr, size_t len) {
	return syscall(3, fd, (uint64_t) ptr, len, 0);
}

int64_t read(uint32_t fd, void* ptr, size_t len) {
	return syscall(4, fd, (uint64_t) ptr, len, 0);
}


int64_t create(const void* path, size_t path_len, const void* filename, size_t filename_len) {
	return syscall(6, (uint64_t) path, path_len ,(uint64_t) filename, filename_len);
}
/// wrapper around create that takes a null terminated path and a null terminated name
int64_t create_n(const char* path, const char* filename) {
	size_t path_len, filename_len;

	path_len = strlen(path);
	filename_len = strlen(filename);

	return create(path, path_len, filename, filename_len);
}

void sputc(char c) {
	write(1, &c, 1);
}

int printf(const char* format, ...) {
	int i = 0;

	const char* current;
	va_list arg;
	va_start(arg, format);
	
	for (current = format; *current != '\0'; current++) {
		while (*current != '%') {
			sputc(*current);
			current++;
			if (*current == '\0') return 0;
		}

		current++;
		switch (*current) {
			case 'd':
				 i = va_arg(arg, int);
				if (i < 0) {
					i = -i;
					sputc('-');
				}
				
				char result[10];
				int start = itoa(i, result);
				write(1, &result[start], 10 - start);
			break;
			case 's':
				printf(va_arg(arg, char*));
			break;
			case '.':
				current++;
				switch (*current) {
					case '*':						
						current++;
						int num = va_arg(arg, int);
						switch (*current) {
							case 's':
								write(1, va_arg(arg, char*), num);
							break;
						}
					break;
				}
			break;
		}
	}
	
	va_end(arg);
	return 0;
}

char getchar() {
	char c;
	read(0, &c, 1);
	return c;
}

/// gets a str from stdin places it in ptr, reads until \n
/// doesn't include \n
/// returns the length of the str
/// if max is reached it will return -1 instead
int getstr(char* ptr, int max) {
	for (int i = 0; i < max; i++) {
		char c = getchar();
		if (c == '\n') return i;
		ptr[i] = c;
	}

	if (getchar() == '\n') return max;
	return -1;
}
