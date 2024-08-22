#include <stdio.h>

// Function declaration
char	*ft_strupcase(char *str);

// Main function to test ft_strupcase
int main(void)
{
    // Test cases
    char test1[] = "hello";
    char test2[] = "WORLD";
    char test3[] = "";
    char test4[] = "MixedCase";
    char test5[] = "12345";
    char test6[] = "hello world!";
    char test7[] = "HELLO123";
    char test8[] = "lowercase";
    char test9[] = "UPPERCASE";
    char test10[] = "edgecaseZz";

    // Testing and printing the results
    printf("Test 1: \"%s\" => \"%s\"\n", test1, ft_strupcase(test1)); // Expected output: "HELLO"
    printf("Test 2: \"%s\" => \"%s\"\n", test2, ft_strupcase(test2)); // Expected output: "WORLD"
    printf("Test 3: \"%s\" => \"%s\"\n", test3, ft_strupcase(test3)); // Expected output: ""
    printf("Test 4: \"%s\" => \"%s\"\n", test4, ft_strupcase(test4)); // Expected output: "MIXEDCASE"
    printf("Test 5: \"%s\" => \"%s\"\n", test5, ft_strupcase(test5)); // Expected output: "12345"
    printf("Test 6: \"%s\" => \"%s\"\n", test6, ft_strupcase(test6)); // Expected output: "HELLO WORLD!"
    printf("Test 7: \"%s\" => \"%s\"\n", test7, ft_strupcase(test7)); // Expected output: "HELLO123"
    printf("Test 8: \"%s\" => \"%s\"\n", test8, ft_strupcase(test8)); // Expected output: "LOWERCASE"
    printf("Test 9: \"%s\" => \"%s\"\n", test9, ft_strupcase(test9)); // Expected output: "UPPERCASE"
    printf("Test 10: \"%s\" => \"%s\"\n", test10, ft_strupcase(test10)); // Expected output: "EDGECASEZZ"

    return 0;
}