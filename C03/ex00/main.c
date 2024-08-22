#include <stdio.h>

// Function declaration
int	ft_strcmp(char *s1, char *s2);

// Main function to test ft_strcmp
int main(void)
{
    // Test cases
    char *test1_s1 = "hello";
    char *test1_s2 = "hello";
    
    char *test2_s1 = "hello";
    char *test2_s2 = "world";
    
    char *test3_s1 = "abc";
    char *test3_s2 = "abcd";
    
    char *test4_s1 = "";
    char *test4_s2 = "";
    
    char *test5_s1 = "a";
    char *test5_s2 = "b";
    
    char *test6_s1 = "b";
    char *test6_s2 = "a";
    
    char *test7_s1 = "sameprefix";
    char *test7_s2 = "same";
    
    char *test8_s1 = "short";
    char *test8_s2 = "shorter";

    // Testing and printing the results
    printf("Test 1: \"%s\" vs \"%s\" => %d\n", test1_s1, test1_s2, ft_strcmp(test1_s1, test1_s2)); // Expected output: 0
    printf("Test 2: \"%s\" vs \"%s\" => %d\n", test2_s1, test2_s2, ft_strcmp(test2_s1, test2_s2)); // Expected output: a negative number
    printf("Test 3: \"%s\" vs \"%s\" => %d\n", test3_s1, test3_s2, ft_strcmp(test3_s1, test3_s2)); // Expected output: a negative number
    printf("Test 4: \"%s\" vs \"%s\" => %d\n", test4_s1, test4_s2, ft_strcmp(test4_s1, test4_s2)); // Expected output: 0
    printf("Test 5: \"%s\" vs \"%s\" => %d\n", test5_s1, test5_s2, ft_strcmp(test5_s1, test5_s2)); // Expected output: a negative number
    printf("Test 6: \"%s\" vs \"%s\" => %d\n", test6_s1, test6_s2, ft_strcmp(test6_s1, test6_s2)); // Expected output: a positive number
    printf("Test 7: \"%s\" vs \"%s\" => %d\n", test7_s1, test7_s2, ft_strcmp(test7_s1, test7_s2)); // Expected output: a positive number
    printf("Test 8: \"%s\" vs \"%s\" => %d\n", test8_s1, test8_s2, ft_strcmp(test8_s1, test8_s2)); // Expected output: a negative number

    return 0;
}