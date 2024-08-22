#include <stdio.h>

// Function prototypes
int	ft_isspace(char c);
int	ft_base_check(int *base_size, char *base);
int	ft_is_in_base(char c, char *base, int *position);
int	ft_atoi_base(char *str, char *base);

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
    char *test11 = "42abc123";  // Should stop at non-base characters

    // Base cases
    char *base2 = "01"; // Binary
    //char *base8 = "01234567"; // Octal
    char *base10 = "0123456789"; // Decimal
    char *base16 = "0123456789ABCDEF"; // Hexadecimal
    char *base_invalid1 = "01234+567"; // Invalid base (contains '+')
    char *base_invalid2 = "012344567"; // Invalid base (contains duplicate '4')

    // Expected outputs
    int expected1_bin = 0;
    int expected2_bin = 1; // Only the first digit '1' will be considered
    int expected3_bin = 0; // '-' is not in the base
    int expected4_bin = 1; // Only the first digit '1' will be considered
    int expected5_bin = 0; // '-' is not in the base
    int expected6_bin = 1; // Only the first digit '1' will be considered
    int expected7_bin = 0;
    int expected8_bin = 0;
    int expected9_bin = 1; // Only the first digit '1' will be considered
    int expected10_bin = 0; 
    int expected11_bin = 1; // Only the first digit '1' will be considered

    // Testing and printing the results for binary base
    printf("Binary Base Tests:\n");
    printf("Test 1: \"%s\" => %d (Expected: %d)\n", test1, ft_atoi_base(test1, base2), expected1_bin);
    printf("Test 2: \"%s\" => %d (Expected: %d)\n", test2, ft_atoi_base(test2, base2), expected2_bin);
    printf("Test 3: \"%s\" => %d (Expected: %d)\n", test3, ft_atoi_base(test3, base2), expected3_bin);
    printf("Test 4: \"%s\" => %d (Expected: %d)\n", test4, ft_atoi_base(test4, base2), expected4_bin);
    printf("Test 5: \"%s\" => %d (Expected: %d)\n", test5, ft_atoi_base(test5, base2), expected5_bin);
    printf("Test 6: \"%s\" => %d (Expected: %d)\n", test6, ft_atoi_base(test6, base2), expected6_bin);
    printf("Test 7: \"%s\" => %d (Expected: %d)\n", test7, ft_atoi_base(test7, base2), expected7_bin);
    printf("Test 8: \"%s\" => %d (Expected: %d)\n", test8, ft_atoi_base(test8, base2), expected8_bin);
    printf("Test 9: \"%s\" => %d (Expected: %d)\n", test9, ft_atoi_base(test9, base2), expected9_bin);
    printf("Test 10: \"%s\" => %d (Expected: %d)\n", test10, ft_atoi_base(test10, base2), expected10_bin);
    printf("Test 11: \"%s\" => %d (Expected: %d)\n", test11, ft_atoi_base(test11, base2), expected11_bin);

    // Expected outputs for decimal base
    int expected1_dec = 0;
    int expected2_dec = 123;
    int expected3_dec = -456;
    int expected4_dec = 7890;
    int expected5_dec = -2147483648;
    int expected6_dec = 2147483647;
    int expected7_dec = 42;
    int expected8_dec = -42;
    int expected9_dec = 123;
    int expected10_dec = 123;
    int expected11_dec = 42;

    // Testing and printing the results for decimal base
    printf("\nDecimal Base Tests:\n");
    printf("Test 1: \"%s\" => %d (Expected: %d)\n", test1, ft_atoi_base(test1, base10), expected1_dec);
    printf("Test 2: \"%s\" => %d (Expected: %d)\n", test2, ft_atoi_base(test2, base10), expected2_dec);
    printf("Test 3: \"%s\" => %d (Expected: %d)\n", test3, ft_atoi_base(test3, base10), expected3_dec);
    printf("Test 4: \"%s\" => %d (Expected: %d)\n", test4, ft_atoi_base(test4, base10), expected4_dec);
    printf("Test 5: \"%s\" => %d (Expected: %d)\n", test5, ft_atoi_base(test5, base10), expected5_dec);
    printf("Test 6: \"%s\" => %d (Expected: %d)\n", test6, ft_atoi_base(test6, base10), expected6_dec);
    printf("Test 7: \"%s\" => %d (Expected: %d)\n", test7, ft_atoi_base(test7, base10), expected7_dec);
    printf("Test 8: \"%s\" => %d (Expected: %d)\n", test8, ft_atoi_base(test8, base10), expected8_dec);
    printf("Test 9: \"%s\" => %d (Expected: %d)\n", test9, ft_atoi_base(test9, base10), expected9_dec);
    printf("Test 10: \"%s\" => %d (Expected: %d)\n", test10, ft_atoi_base(test10, base10), expected10_dec);
    printf("Test 11: \"%s\" => %d (Expected: %d)\n", test11, ft_atoi_base(test11, base10), expected11_dec);

    // Expected outputs for hexadecimal base
    int expected1_hex = 0;
    int expected2_hex = 0x123; // Equivalent to 291 in decimal
    int expected3_hex = 0; // '-' is not in the base
    int expected4_hex = 0x7890; // Equivalent to 30864 in decimal
    int expected5_hex = 0; // '-' is not in the base
    int expected6_hex = 0x7FFFFFFF; // Equivalent to 2147483647 in decimal
    int expected7_hex = 0x42; // Equivalent to 66 in decimal
    int expected8_hex = 0; // '-' is not in the base
    int expected9_hex = 0x123; // Equivalent to 291 in decimal
    int expected10_hex = 0x123; // Equivalent to 291 in decimal
    int expected11_hex = 0x42; // Equivalent to 66 in decimal

    // Testing and printing the results for hexadecimal base
    printf("\nHexadecimal Base Tests:\n");
    printf("Test 1: \"%s\" => %d (Expected: %d)\n", test1, ft_atoi_base(test1, base16), expected1_hex);
    printf("Test 2: \"%s\" => %d (Expected: %d)\n", test2, ft_atoi_base(test2, base16), expected2_hex);
    printf("Test 3: \"%s\" => %d (Expected: %d)\n", test3, ft_atoi_base(test3, base16), expected3_hex);
    printf("Test 4: \"%s\" => %d (Expected: %d)\n", test4, ft_atoi_base(test4, base16), expected4_hex);
    printf("Test 5: \"%s\" => %d (Expected: %d)\n", test5, ft_atoi_base(test5, base16), expected5_hex);
    printf("Test 6: \"%s\" => %d (Expected: %d)\n", test6, ft_atoi_base(test6, base16), expected6_hex);
    printf("Test 7: \"%s\" => %d (Expected: %d)\n", test7, ft_atoi_base(test7, base16), expected7_hex);
    printf("Test 8: \"%s\" => %d (Expected: %d)\n", test8, ft_atoi_base(test8, base16), expected8_hex);
    printf("Test 9: \"%s\" => %d (Expected: %d)\n", test9, ft_atoi_base(test9, base16), expected9_hex);
    printf("Test 10: \"%s\" => %d (Expected: %d)\n", test10, ft_atoi_base(test10, base16), expected10_hex);
    printf("Test 11: \"%s\" => %d (Expected: %d)\n", test11, ft_atoi_base(test11, base16), expected11_hex);

    // Invalid base tests
    printf("\nInvalid Base Tests (should return 0):\n");
    printf("Test 2 with invalid base 1: \"%s\" => %d (Expected: 0)\n", test2, ft_atoi_base(test2, base_invalid1));
    printf("Test 3 with invalid base 2: \"%s\" => %d (Expected: 0)\n", test3, ft_atoi_base(test3, base_invalid2));

    return 0;
}
