// Main function for testing ft_putnbr_base
#include <unistd.h>

void    ft_putchar(char c);
int     ft_base_check(int *base_size, char *base);
void    ft_putnbr_base(int nbr, char *base);

int main(void)
{
    // Test cases
    int test1 = 0;
    int test2 = 123;
    int test3 = -456;
    int test4 = 7890;
    int test5 = -2147483648; // Minimum value of a signed 32-bit integer
    int test6 = 2147483647;  // Maximum value of a signed 32-bit integer

    // Base cases
    char *base2 = "01"; // Binary
    char *base8 = "01234567"; // Octal
    char *base10 = "0123456789"; // Decimal
    char *base16 = "0123456789ABCDEF"; // Hexadecimal
    char *base_invalid1 = "01234+567"; // Invalid base (contains '+')
    char *base_invalid2 = "012344567"; // Invalid base (contains duplicate '4')

    // Testing and printing the results
    write(1, "Binary: ", 8);
    ft_putnbr_base(test1, base2); write(1, "\n", 1);
    ft_putnbr_base(test2, base2); write(1, "\n", 1);
    ft_putnbr_base(test3, base2); write(1, "\n", 1);
    ft_putnbr_base(test4, base2); write(1, "\n", 1);
    ft_putnbr_base(test5, base2); write(1, "\n", 1);
    ft_putnbr_base(test6, base2); write(1, "\n", 1);

    write(1, "Octal: ", 7);
    ft_putnbr_base(test1, base8); write(1, "\n", 1);
    ft_putnbr_base(test2, base8); write(1, "\n", 1);
    ft_putnbr_base(test3, base8); write(1, "\n", 1);
    ft_putnbr_base(test4, base8); write(1, "\n", 1);
    ft_putnbr_base(test5, base8); write(1, "\n", 1);
    ft_putnbr_base(test6, base8); write(1, "\n", 1);

    write(1, "Decimal: ", 9);
    ft_putnbr_base(test1, base10); write(1, "\n", 1);
    ft_putnbr_base(test2, base10); write(1, "\n", 1);
    ft_putnbr_base(test3, base10); write(1, "\n", 1);
    ft_putnbr_base(test4, base10); write(1, "\n", 1);
    ft_putnbr_base(test5, base10); write(1, "\n", 1);
    ft_putnbr_base(test6, base10); write(1, "\n", 1);

    write(1, "Hexadecimal: ", 13);
    ft_putnbr_base(test1, base16); write(1, "\n", 1);
    ft_putnbr_base(test2, base16); write(1, "\n", 1);
    ft_putnbr_base(test3, base16); write(1, "\n", 1);
    ft_putnbr_base(test4, base16); write(1, "\n", 1);
    ft_putnbr_base(test5, base16); write(1, "\n", 1);
    ft_putnbr_base(test6, base16); write(1, "\n", 1);

    write(1, "Invalid base tests (should produce no output):\n", 46);
    ft_putnbr_base(test2, base_invalid1); write(1, "\n", 1);
    ft_putnbr_base(test3, base_invalid2); write(1, "\n", 1);

    return 0;
}