#include <stdio.h>

// Function declaration
int	ft_str_is_printable(char *str);

// Main function to test ft_str_is_printable
int main(void)
{
    // Test cases
    char *test1 = "Hello, World!";
    char *test2 = "Printable characters!";
    char *test3 = "";
    char *test4 = "This\tis\ta\ttab";       // Contains tabs
    char *test5 = "Line\nbreak";            // Contains a newline
    char *test6 = "Null\0character";        // Contains a null character
    char *test7 = "Space is printable ";    // Contains a space
    char *test8 = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"; // All printable symbols
    char *test9 = "\x1F";                   // Non-printable ASCII character (Unit Separator)
    char *test10 = "\x7F";                  // Non-printable ASCII character (Delete)
    char *test11 = "Printable~";            // Ends with printable character

    // Testing and printing the results
    printf("Test 1: \"%s\" => %d\n", test1, ft_str_is_printable(test1)); // Expected output: 1
    printf("Test 2: \"%s\" => %d\n", test2, ft_str_is_printable(test2)); // Expected output: 1
    printf("Test 3: \"%s\" => %d\n", test3, ft_str_is_printable(test3)); // Expected output: 1
    printf("Test 4: \"%s\" => %d\n", test4, ft_str_is_printable(test4)); // Expected output: 0
    printf("Test 5: \"%s\" => %d\n", test5, ft_str_is_printable(test5)); // Expected output: 0
    printf("Test 6: \"%s\" => %d\n", test6, ft_str_is_printable(test6)); // Expected output: 0
    printf("Test 7: \"%s\" => %d\n", test7, ft_str_is_printable(test7)); // Expected output: 1
    printf("Test 8: \"%s\" => %d\n", test8, ft_str_is_printable(test8)); // Expected output: 1
    printf("Test 9: \"%s\" => %d\n", test9, ft_str_is_printable(test9)); // Expected output: 0
    printf("Test 10: \"%s\" => %d\n", test10, ft_str_is_printable(test10)); // Expected output: 0
    printf("Test 11: \"%s\" => %d\n", test11, ft_str_is_printable(test11)); // Expected output: 1

    return 0;
}
