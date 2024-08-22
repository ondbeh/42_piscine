#include <stdio.h>
#include <stdlib.h>

// The ft_map function from your code
int *ft_map(int *tab, int length, int (*f)(int));

// Sample function to square a number
int square(int n) {
    return n * n;
}

// Main function to test ft_map
int main() {
    int numbers[] = {1, 2, 3, 4, 5};  // Sample array
    int length = 5;  // Length of the array
    int *result;
    int i;

    // Call ft_map with the array and the square function
    result = ft_map(numbers, length, square);

    // Check if malloc failed
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Print the original array and the resulting array
    printf("Original array: ");
    for (i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Mapped array (squared): ");
    for (i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);

    return 0;
}
