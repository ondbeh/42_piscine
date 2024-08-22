#include "ft_putstr.c"

void ft_putstr (char *str);

int main(void)
{
    char *str;

    str = "Hello World";

    ft_putstr(str);

    return 0;
}