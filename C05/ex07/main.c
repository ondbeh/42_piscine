#include <stdio.h>

// Function prototypes
int ft_find_next_prime(int nb);

int main(void) {
    int test_values[] = {-10, 0, 1, 2, 3, 4, 10, 11, 13, 14, 16, 17, 18, 19, 20, 23, 24, 25, 26, 100, 101, 2147483458, -2147000118};
    int size = sizeof(test_values) / sizeof(test_values[0]);

    printf("Testing ft_find_next_prime:\n");
    for (int i = 0; i < size; i++) {
        int result = ft_find_next_prime(test_values[i]);
        printf("ft_find_next_prime(%d) = %d\n", test_values[i], result);
    }

    return 0;
}