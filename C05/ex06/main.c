#include <stdio.h>

// Function prototype
int ft_is_prime(int nb);

int main(void) {
    // Test cases including edge cases
    int test_values[] = {
        -10, -1, 0, 1, 2, 3, 4, 5, 10, 13, 16, 17, 18, 19, 20, 23, 24, 25, 29, 30, 31, 37, 38, 39, 2147483647
    };
    int size = sizeof(test_values) / sizeof(test_values[0]);

    // Print header
    printf("Testing ft_is_prime:\n");

    // Iterate through test cases
    for (int i = 0; i < size; i++) {
        int result = ft_is_prime(test_values[i]);
        printf("ft_is_prime(%d) = %d\n", test_values[i], result);
    }

    return 0;
}
