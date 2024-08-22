#include <stdio.h>

// Function prototype
int ft_sqrt(int nb);

int main(void) {
    // Test cases including edge cases
    int test_values[] = {
        -10, 0, 1, 2, 3, 4, 5, 9, 10, 15, 16, 24, 25, 26, 99, 100, 101, 144, 2147395600, 2147483647
    };
    int size = sizeof(test_values) / sizeof(test_values[0]);

    // Print header
    printf("Testing ft_sqrt:\n");

    // Iterate through test cases
    for (int i = 0; i < size; i++) {
        int result = ft_sqrt(test_values[i]);
        printf("ft_sqrt(%d) = %d\n", test_values[i], result);
    }

    return 0;
}
