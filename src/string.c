#include "string.h"
size_t strlen(const char* str) {
	size_t len = 0;
	const char* ch = str;

	while (*ch != 0) {
		ch++;
		len++;
	}
	
	return len;
}
