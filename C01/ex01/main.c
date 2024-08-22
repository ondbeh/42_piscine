#include "ft_ultimate_ft.c"
#include <stdio.h>

void    ft_ultimate_ft(int *********nbr);

int main( void )
{
    int value = 0;
    int *ptr1 = &value;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;
    int *****ptr5 = &ptr4;
    int ******ptr6 = &ptr5;
    int *******ptr7 = &ptr6;
    int ********ptr8 = &ptr7;
    int *********ptr9 = &ptr8;

    printf("Before: %d\n", value);

    ft_ultimate_ft(ptr9);

    printf("After: %d\n", value);

    return 0;
}
