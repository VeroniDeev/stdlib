#include "sys.h"

void pexit() {
	syscall(0, 0, 0 , 0, 0);
}
