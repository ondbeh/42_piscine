void    ft_putnbr(int nb);
void    ft_putchar(char c);

// Main function for testing ft_putnbr
int main(void)
{
    // Test cases
    int test1 = 0;
    int test2 = 1;
    int test3 = -4;
    int test4 = 7890;
    int test5 = -2147483648; // Minimum value of a signed 32-bit integer
    int test6 = 2147483647;  // Maximum value of a signed 32-bit integer

    // Calling ft_putnbr with different test cases
    ft_putnbr(test1); ft_putchar('\n'); // Expected output: 0
    ft_putnbr(test2); ft_putchar('\n'); // Expected output: 123
    ft_putnbr(test3); ft_putchar('\n'); // Expected output: -456
    ft_putnbr(test4); ft_putchar('\n'); // Expected output: 7890
    ft_putnbr(test5); ft_putchar('\n'); // Expected output: -2147483648
    ft_putnbr(test6); ft_putchar('\n'); // Expected output: 2147483647

    return 0;
}