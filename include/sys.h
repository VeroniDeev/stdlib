#include <stdint.h>
#include <stddef.h>
static inline int64_t syscall(uint64_t num, uint64_t arg0, uint64_t arg1, uint64_t arg3, uint64_t arg4) {
    int64_t result;
    asm volatile (
        "mov %1, %%rax\n" 
        "mov %2, %%rdi\n"  
        "mov %3, %%rsi\n"  
        "mov %4, %%rdx\n"          
	"mov %5, %%rcx\n"  
        "int $0x80\n"      
        "mov %%rax, %0\n"  
        : "=r" (result)    
        : "r" (num), "r" (arg0), "r" (arg1), "r" (arg3), "r" (arg4)
        : "rax", "rdi", "rsi", "rdx"  
    );
    return result;
}
