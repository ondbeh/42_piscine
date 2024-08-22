#include <stdio.h>

// Function prototype for ft_putstr_non_printable
void ft_putstr_non_printable(char *str);

int main() {
    // Test 1: String with a newline character
    char test1[] = "Coucou\ntu vas bien ?";
    printf("Test 1:\nInput: %s\nOutput: ", test1);
    ft_putstr_non_printable(test1);
    printf("\n\n");

    // Test 2: String with non-printable characters at the start, middle, and end
    char test2[] = "\tHello\x07World\x1B!";
    printf("Test 2:\nInput: %s\nOutput: ", test2);
    ft_putstr_non_printable(test2);
    printf("\n\n");

    // Test 3: String with all printable characters
    char test3[] = "This is a test string.";
    printf("Test 3:\nInput: %s\nOutput: ", test3);
    ft_putstr_non_printable(test3);
    printf("\n\n");

    // Test 4: Empty string
    char test4[] = "";
    printf("Test 4:\nInput: (empty string)\nOutput: ");
    ft_putstr_non_printable(test4);
    printf("\n\n");

    // Test 5: String with extended ASCII characters
    char test5[] = "Extended\\x80\\x99ASCII\\xA0Characters";
    printf("Test 5:\nInput: %s\nOutput: ", test5);
    ft_putstr_non_printable(test5);
    printf("\n");

    return 0;
}
