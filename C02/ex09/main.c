#include <stdio.h>

// Function prototype for ft_strcapitalize
char *ft_strcapitalize(char *str);

int main() {
    char test1[] = "hello world! this is a test.";
    char test2[] = "123abc DEF ghi!";
    char test3[] = "HELLO, HOW ARE YOU?";
    char test4[] = "multiple     spaces   between words";
    char test5[] = "some-mixed_case+with/special*characters";

    printf("Original: %s\n", test1);
    printf("Capitalized: %s\n\n", ft_strcapitalize(test1));

    printf("Original: %s\n", test2);
    printf("Capitalized: %s\n\n", ft_strcapitalize(test2));

    printf("Original: %s\n", test3);
    printf("Capitalized: %s\n\n", ft_strcapitalize(test3));

    printf("Original: %s\n", test4);
    printf("Capitalized: %s\n\n", ft_strcapitalize(test4));

    printf("Original: %s\n", test5);
    printf("Capitalized: %s\n\n", ft_strcapitalize(test5));

    return 0;
}
