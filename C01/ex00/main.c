#include "ft_ft.c"
#include <stdio.h>

void    ft_ft(int *nbr);

int main(void)
{
    int number;

    number = 57;

    printf("%d \n", number );

    ft_ft(&number);

    printf("%d \n", number );

    return 0;
}
