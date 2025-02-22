#include <stdio.h>
#define NOT_PRESENT -1

typedef long (*long_func_ptr)(int);

long fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long_func_ptr original_provider; 
long_func_ptr fibonacci_provider;

long results[100] = { [0 ... 99] = NOT_PRESENT };

long cache(int val) {
    if (results[val] == NOT_PRESENT)
        results[val] = (*original_provider)(val); 
    return results[val];
}

int main() {
    original_provider = fibonacci;
    fibonacci_provider = cache;

    int n;
    printf("Enter a number to compute Fibonacci: ");
    scanf("%d", &n);

    if (n < 0 || n >= 100) {
        printf("Please enter a number between 0 and 99.\n");
        return 1; 
    }

    printf("Fibonacci of %d is %ld\n", n, (*fibonacci_provider)(n));

    return 0;
}
