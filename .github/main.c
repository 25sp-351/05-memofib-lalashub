#include <stdio.h>
#include "memofib.h"

int main(void) {
    original_provider = fibonacci_actual;
    fibonacci_provider = cache_fib;

    initialize_cache();

    while (1) {
        int userIndex;
        printf("Enter a number to compute Fibonacci (non-number to quit): ");

        int result = scanf("%d", &userIndex);
        if (result != 1) {
            printf("Non-numeric input detected. Exiting...\n");
            break;
        }

        if (userIndex < 0 || userIndex >= 100) {
            printf("Please enter a number between 0 and 99.\n");
            continue;
        }

        long fibValue = fibonacci_provider(userIndex);
        printf("Fibonacci of %d is %ld\n", userIndex, fibValue);
    }

    return 0;
}
