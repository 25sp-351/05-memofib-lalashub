#include <stdio.h>

#define NOT_PRESENT -1

// Function pointer type for Fibonacci calculation
typedef long (*long_func_ptr)(int);

// Original Fibonacci function (recursive)
long fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function pointer for the Fibonacci provider
long_func_ptr original_provider; // MOVE THIS LINE UP
long_func_ptr fibonacci_provider;

// Cache array for memoization
long results[100] = { [0 ... 99] = NOT_PRESENT };

// Caching (memoizing) function
long cache(int val) {
    if (results[val] == NOT_PRESENT)
        results[val] = (*original_provider)(val); // Now original_provider is declared
    return results[val];
}

int main() {
    // Install the original Fibonacci function
    original_provider = fibonacci;
    fibonacci_provider = cache;

    // Ask user for input
    int n;
    printf("Enter a number to compute Fibonacci: ");
    scanf("%d", &n);

    // Validate input (optional)
    if (n < 0 || n >= 100) {
        printf("Please enter a number between 0 and 99.\n");
        return 1; // Exit with error
    }

    // Compute and display result
    printf("Fibonacci of %d is %ld\n", n, (*fibonacci_provider)(n));

    return 0;
}
