#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char *ft_convert_base(char *nbr, char *base_from, char *base_to);

void test_ft_convert_base(char *nbr, char *base_from, char *base_to, char *expected) {
    char *result = ft_convert_base(nbr, base_from, base_to);
    if (expected == NULL) {
        if (result == NULL)
            printf("PASS: %s from base %s to base %s => NULL (expected: NULL)\n", nbr, base_from, base_to);
        else
            printf("FAIL: %s from base %s to base %s => NULL (expected: %s)\n", nbr, base_from, base_to, expected);
    } else {
        if (strcmp(result, expected) == 0)
            printf("PASS: %s from base %s to base %s => %s\n", nbr, base_from, base_to, result);
        else
            printf("FAIL: %s from base %s to base %s => %s (expected: %s)\n", nbr, base_from, base_to, result, expected);
    }
    free(result); // assuming ft_convert_base allocates memory
}

int main() {
    // Valid cases
    test_ft_convert_base("1A010A", "01", "0123456789", "10");
    test_ft_convert_base("A", "0123456789ABCDEF", "0123456789", "10");
    test_ft_convert_base("-1010", "01", "0123456789", "-10");
    test_ft_convert_base("   -10", "0123456789", "01", "-1010");
    test_ft_convert_base("+7F", "0123456789ABCDEF", "01234567", "177");

    // Invalid base cases
    test_ft_convert_base("10", "0123456789", "01234+", NULL);
    test_ft_convert_base("10", "01234+6789", "0123456789", NULL);
    test_ft_convert_base("10", "01", "01", "10");

    // Invalid number cases
    test_ft_convert_base("1A", "01", "0123456789", "1");
    test_ft_convert_base("", "0123456789", "0123456789", "");

    return 0;
}
