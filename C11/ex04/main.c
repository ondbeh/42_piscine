#include <stdio.h>

// Prototyping the ft_is_sort function (without implementation)
int ft_is_sort(int *tab, int length, int (*f)(int, int));

// Example comparison function: ascending order
int ascending(int a, int b) {
    return (a - b);
}

// Example comparison function: descending order
int descending(int a, int b) {
    return (b - a);
}

// Main function to test ft_is_sort
int main() {
    int sorted_asc[] = {1, 2, 3, 4, 5};
    int sorted_desc[] = {5, 4, 3, 2, 1};
    int unsorted[] = {353, 15, 6848, 3543846};
    int length = 5;

    // Test sorted in ascending order
    if (ft_is_sort(sorted_asc, length, descending)) {
        printf("Array sorted_asc is sorted.\n");
    } else {
        printf("Array sorted_asc is NOT sorted.\n");
    }

    // Test sorted in descending order
    if (ft_is_sort(sorted_desc, length, ascending)) {
        printf("Array sorted_desc is sorted.\n");
    } else {
        printf("Array sorted_desc is NOT sorted.\n");
    }

    // Test unsorted array
    if (ft_is_sort(unsorted, 4, descending)) {
        printf("Array unsorted is sorted.\n");
    } else {
        printf("Array unsorted is NOT sorted.\n");
    }

    return 0;
}
