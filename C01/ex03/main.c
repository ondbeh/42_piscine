#include "ft_div_mod.c"
#include <stdio.h>

void    ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
    int a;
    int b;
    int div;
    int mod;


    a = 58;
    b = 10;

    printf("%d, %d\n", a, b );

    ft_div_mod( a, b, &div, &mod);

    printf("%d, %d\n", div, mod );


    return 0;
}
