#ifndef FIB_H
#define FIB_H

typedef long (*long_func_ptr)(int);

long fibonacci_actual(int index);

long cache_fib(int index);

void initialize_cache(void);

extern long_func_ptr original_provider;
extern long_func_ptr fibonacci_provider;

#endif
