#include <stdio.h>

// The ft_any function from your code
int	ft_count_if(char **tab, int length, int (*f)(char*));

// Sample function to check if a string contains the character 'a'
int contains_a(char *str) {
    while (*str) {
        if (*str == 'a') {
            return 1;
        }
        str++;
    }
    return 0;
}

// Main function to test ft_any
int main() {
    char *words[] = {"hello", "wald", "42", "apple", "code", NULL};  // Sample array of strings
    int result;

    // Call ft_any with the array of strings and the contains_a function
    result = ft_count_if(words, 5, &contains_a);

    // Print the result
    if (result) {
        printf("%d words contain the character 'a'.\n", result);
    } else {
        printf("No strings contain the character 'a'.\n");
    }

    return 0;
}
