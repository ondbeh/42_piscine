#include <stdio.h>

// Function declaration
int	ft_str_is_numeric(char *str);

// Main function to test ft_str_is_numeric
int main(void)
{
	// Test cases
	char *test1 = "1234567890";
	char *test2 = "42";
	char *test3 = "";
	char *test4 = "123abc";
	char *test5 = "abc123";
	char *test6 = "!@#123";

	// Testing and printing the results
	printf("Test 1: \"%s\" => %d\n", test1, ft_str_is_numeric(test1)); // Expected output: 1
	printf("Test 2: \"%s\" => %d\n", test2, ft_str_is_numeric(test2)); // Expected output: 1
	printf("Test 3: \"%s\" => %d\n", test3, ft_str_is_numeric(test3)); // Expected output: 1
	printf("Test 4: \"%s\" => %d\n", test4, ft_str_is_numeric(test4)); // Expected output: 0
	printf("Test 5: \"%s\" => %d\n", test5, ft_str_is_numeric(test5)); // Expected output: 0
	printf("Test 6: \"%s\" => %d\n", test6, ft_str_is_numeric(test6)); // Expected output: 0

	return 0;
}