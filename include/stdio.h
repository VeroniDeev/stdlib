#include <stdint.h>
#include <stddef.h>
// FS
int64_t open(const void* path_ptr, size_t len);
int64_t close(uint32_t fd);
int64_t open_n(const char* path);

int64_t write(uint32_t fd, const void* ptr, size_t len);
int64_t read(uint32_t fd, void* ptr, size_t len);

int64_t create(const void* path, size_t path_len, const void* filename, size_t filename_len);
/// wrapper around create that takes a null terminated path and a null terminated name
int64_t create_n(const char* path, const char* filename);
// COMMON
/// puts a char in stdin
static inline void sputc(char c) {
	write(1, &c, 1);
}
int printf(const char* format, ...);

char getchar();

/// gets a str from stdin places it in ptr, reads until \n
/// doesn't include \n
/// returns the length of the str
/// if max is reached it will return -1 instead
int getstr(char* ptr, int max);
