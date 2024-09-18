#include "sys.h"

void pexit() { syscall(0, 0, 0, 0, 0); }
void yield() { syscall(1, 0, 0, 0, 0); }
void wait(int64_t pid) { syscall(11, pid, 0, 0, 0); }
