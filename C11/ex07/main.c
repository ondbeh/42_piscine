#include <stdio.h>
#include <string.h>

// Prototype for the ft_advanced_sort_string_tab function
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

// Comparison function for sorting strings in ascending ASCII order
int ft_strcmp_asc(char *s1, char *s2) {
    return strcmp(s1, s2);
}

// Comparison function for sorting strings in descending ASCII order
int ft_strcmp_desc(char *s1, char *s2) {
    return strcmp(s2, s1);
}

int main() {
    // Define an array of strings (null-terminated)
    char *tab[] = {
        "apple",
        "orange",
        "banana",
        "grape",
        "pineapple",
        "kiwi",
        NULL
    };

    // Print the array before sorting
    printf("Before sorting:\n");
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }

    // Sort the array in ascending ASCII order
    ft_advanced_sort_string_tab(tab, ft_strcmp_asc);

    // Print the array after sorting in ascending order
    printf("\nAfter sorting in ascending order:\n");
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }

    // Sort the array in descending ASCII order
    ft_advanced_sort_string_tab(tab, ft_strcmp_desc);

    // Print the array after sorting in descending order
    printf("\nAfter sorting in descending order:\n");
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }

    return 0;
}
