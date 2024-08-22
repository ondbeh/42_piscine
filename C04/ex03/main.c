#include <stdio.h>

int ft_atoi(char *c);

// Main function for testing ft_atoi
int main(void)
{
    // Test cases
    char *test1 = "0";
    char *test2 = "123";
    char *test3 = "-456";
    char *test4 = "7890";
    char *test5 = "-2147483648"; // Minimum value of a signed 32-bit integer
    char *test6 = "2147483647";  // Maximum value of a signed 32-bit integer
    char *test7 = "   42";
    char *test8 = "   -42";
    char *test9 = "+123";
    char *test10 = "  +00123";
    char *test11 = "42abc123";  // Should stop at non-numeric characters

    // Expected outputs
    int expected1 = 0;
    int expected2 = 123;
    int expected3 = -456;
    int expected4 = 7890;
    int expected5 = -2147483648;
    int expected6 = 2147483647;
    int expected7 = 42;
    int expected8 = -42;
    int expected9 = 123;
    int expected10 = 123;
    int expected11 = 42;

    // Testing and printing the results
    printf("Test 1: \"%s\" => %d (Expected: %d)\n", test1, ft_atoi(test1), expected1);
    printf("Test 2: \"%s\" => %d (Expected: %d)\n", test2, ft_atoi(test2), expected2);
    printf("Test 3: \"%s\" => %d (Expected: %d)\n", test3, ft_atoi(test3), expected3);
    printf("Test 4: \"%s\" => %d (Expected: %d)\n", test4, ft_atoi(test4), expected4);
    printf("Test 5: \"%s\" => %d (Expected: %d)\n", test5, ft_atoi(test5), expected5);
    printf("Test 6: \"%s\" => %d (Expected: %d)\n", test6, ft_atoi(test6), expected6);
    printf("Test 7: \"%s\" => %d (Expected: %d)\n", test7, ft_atoi(test7), expected7);
    printf("Test 8: \"%s\" => %d (Expected: %d)\n", test8, ft_atoi(test8), expected8);
    printf("Test 9: \"%s\" => %d (Expected: %d)\n", test9, ft_atoi(test9), expected9);
    printf("Test 10: \"%s\" => %d (Expected: %d)\n", test10, ft_atoi(test10), expected10);
    printf("Test 11: \"%s\" => %d (Expected: %d)\n", test11, ft_atoi(test11), expected11);

    return 0;
}