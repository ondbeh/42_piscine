#include <unistd.h>

void	ft_print_combn(int n);

int main(void)
{
    int n; 

    n = 0;

    while (n <= 10)
    {
        ft_print_combn(n++);
        write (1, "\n\n", 2);
    }
    return (0);
}