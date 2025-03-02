#include "memofib.h"
#include <stdio.h>  
#include <stddef.h>  

#define NOT_PRESENT -1
#define MAX_FIB     100

static long results[MAX_FIB];

long_func_ptr original_provider = NULL;
long_func_ptr fibonacci_provider = NULL;

void initialize_cache(void) {
    for (int i = 0; i < MAX_FIB; i++) {
        results[i] = NOT_PRESENT;
    }
}

long fibonacci_actual(int index) {
    if (index <= 1) {
        return index;
    }
    return fibonacci_provider(index - 1) + fibonacci_provider(index - 2);
}

long cache_fib(int index) {
    if (index < 0 || index >= MAX_FIB) {
        return -1;
    }
    if (results[index] == NOT_PRESENT) {
        results[index] = original_provider(index);
    }
    return results[index];
}
