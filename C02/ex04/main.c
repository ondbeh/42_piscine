#include <stdio.h>

// Function declaration
int	ft_str_is_lowercase(char *str);

// Main function to test ft_str_is_lowercase
int main(void)
{
	char *test1 = "abcdefghijklmnopqrstuvwxyz";
    char *test2 = "hello";
    char *test3 = "";
    char *test4 = "Hello";
    char *test5 = "hello123";
    char *test6 = "hello!";
    char *test7 = "HELLO";
    char *test8 = "a";
    char *test9 = "z";
    char *test10 = "`";
    char *test11 = "{";
    char *test12 = "abcz";

    // Testing and printing the results
    printf("Test 1: \"%s\" => %d\n", test1, ft_str_is_lowercase(test1)); // Expected output: 1
    printf("Test 2: \"%s\" => %d\n", test2, ft_str_is_lowercase(test2)); // Expected output: 1
    printf("Test 3: \"%s\" => %d\n", test3, ft_str_is_lowercase(test3)); // Expected output: 1
    printf("Test 4: \"%s\" => %d\n", test4, ft_str_is_lowercase(test4)); // Expected output: 0
    printf("Test 5: \"%s\" => %d\n", test5, ft_str_is_lowercase(test5)); // Expected output: 0
    printf("Test 6: \"%s\" => %d\n", test6, ft_str_is_lowercase(test6)); // Expected output: 0
    printf("Test 7: \"%s\" => %d\n", test7, ft_str_is_lowercase(test7)); // Expected output: 0
    printf("Test 8: \"%s\" => %d\n", test8, ft_str_is_lowercase(test8)); // Expected output: 1
    printf("Test 9: \"%s\" => %d\n", test9, ft_str_is_lowercase(test9)); // Expected output: 1
    printf("Test 10: \"%s\" => %d\n", test10, ft_str_is_lowercase(test10)); // Expected output: 0
    printf("Test 11: \"%s\" => %d\n", test11, ft_str_is_lowercase(test11)); // Expected output: 0
    printf("Test 12: \"%s\" => %d\n", test12, ft_str_is_lowercase(test12)); // Expected output: 1

	return 0;
}