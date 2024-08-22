#include <stdio.h>

// Function declaration
int	ft_str_is_uppercase(char *str);

// Main function to test ft_str_is_uppercase
int main(void)
{
    // Test cases
    char *test1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *test2 = "HELLO";
    char *test3 = "";
    char *test4 = "Hello";
    char *test5 = "HELLO123";
    char *test6 = "HELLO!";
    char *test7 = "hello";
    char *test8 = "A";
    char *test9 = "Z";
    char *test10 = "@";
    char *test11 = "[";
    char *test12 = "ABCDZ";

    // Testing and printing the results
    printf("Test 1: \"%s\" => %d\n", test1, ft_str_is_uppercase(test1)); // Expected output: 1
    printf("Test 2: \"%s\" => %d\n", test2, ft_str_is_uppercase(test2)); // Expected output: 1
    printf("Test 3: \"%s\" => %d\n", test3, ft_str_is_uppercase(test3)); // Expected output: 1
    printf("Test 4: \"%s\" => %d\n", test4, ft_str_is_uppercase(test4)); // Expected output: 0
    printf("Test 5: \"%s\" => %d\n", test5, ft_str_is_uppercase(test5)); // Expected output: 0
    printf("Test 6: \"%s\" => %d\n", test6, ft_str_is_uppercase(test6)); // Expected output: 0
    printf("Test 7: \"%s\" => %d\n", test7, ft_str_is_uppercase(test7)); // Expected output: 0
    printf("Test 8: \"%s\" => %d\n", test8, ft_str_is_uppercase(test8)); // Expected output: 1
    printf("Test 9: \"%s\" => %d\n", test9, ft_str_is_uppercase(test9)); // Expected output: 1
    printf("Test 10: \"%s\" => %d\n", test10, ft_str_is_uppercase(test10)); // Expected output: 0
    printf("Test 11: \"%s\" => %d\n", test11, ft_str_is_uppercase(test11)); // Expected output: 0
    printf("Test 12: \"%s\" => %d\n", test12, ft_str_is_uppercase(test12)); // Expected output: 1

    return 0;
}