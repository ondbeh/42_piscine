#include <stdio.h>

// Function declaration
int	ft_strncmp(char *s1, char *s2, unsigned int n);

// Main function to test ft_strncmp
int main(void)
{
    // Test cases
    char *test1_s1 = "hello";
    char *test1_s2 = "hello";
    unsigned int test1_n = 5;

    char *test2_s1 = "hello";
    char *test2_s2 = "world";
    unsigned int test2_n = 3;

    char *test3_s1 = "abc";
    char *test3_s2 = "abcd";
    unsigned int test3_n = 3;

    char *test4_s1 = "";
    char *test4_s2 = "";
    unsigned int test4_n = 1;

    char *test5_s1 = "a";
    char *test5_s2 = "b";
    unsigned int test5_n = 1;

    char *test6_s1 = "b";
    char *test6_s2 = "a";
    unsigned int test6_n = 1;

    char *test7_s1 = "sameprefix";
    char *test7_s2 = "same";
    unsigned int test7_n = 4;

    char *test8_s1 = "short";
    char *test8_s2 = "shorter";
    unsigned int test8_n = 6;

    char *test9_s1 = "test";
    char *test9_s2 = "testcase";
    unsigned int test9_n = 7;

    char *test10_s1 = "123456";
    char *test10_s2 = "123457";
    unsigned int test10_n = 6;

    // Testing and printing the results
    printf("Test 1: \"%s\" vs \"%s\" (n = %d) => %d\n", test1_s1, test1_s2, test1_n, ft_strncmp(test1_s1, test1_s2, test1_n)); // Expected output: 0
    printf("Test 2: \"%s\" vs \"%s\" (n = %d) => %d\n", test2_s1, test2_s2, test2_n, ft_strncmp(test2_s1, test2_s2, test2_n)); // Expected output: a negative number
    printf("Test 3: \"%s\" vs \"%s\" (n = %d) => %d\n", test3_s1, test3_s2, test3_n, ft_strncmp(test3_s1, test3_s2, test3_n)); // Expected output: 0
    printf("Test 4: \"%s\" vs \"%s\" (n = %d) => %d\n", test4_s1, test4_s2, test4_n, ft_strncmp(test4_s1, test4_s2, test4_n)); // Expected output: 0
    printf("Test 5: \"%s\" vs \"%s\" (n = %d) => %d\n", test5_s1, test5_s2, test5_n, ft_strncmp(test5_s1, test5_s2, test5_n)); // Expected output: a negative number
    printf("Test 6: \"%s\" vs \"%s\" (n = %d) => %d\n", test6_s1, test6_s2, test6_n, ft_strncmp(test6_s1, test6_s2, test6_n)); // Expected output: a positive number
    printf("Test 7: \"%s\" vs \"%s\" (n = %d) => %d\n", test7_s1, test7_s2, test7_n, ft_strncmp(test7_s1, test7_s2, test7_n)); // Expected output: 0
    printf("Test 8: \"%s\" vs \"%s\" (n = %d) => %d\n", test8_s1, test8_s2, test8_n, ft_strncmp(test8_s1, test8_s2, test8_n)); // Expected output: a negative number
    printf("Test 9: \"%s\" vs \"%s\" (n = %d) => %d\n", test9_s1, test9_s2, test9_n, ft_strncmp(test9_s1, test9_s2, test9_n)); // Expected output: a negative number
    printf("Test 10: \"%s\" vs \"%s\" (n = %d) => %d\n", test10_s1, test10_s2, test10_n, ft_strncmp(test10_s1, test10_s2, test10_n)); // Expected output: a negative number

    return 0;
}