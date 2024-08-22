#include <stdio.h>


void ft_rev_int_tab(int *tab, int size);

int main(void){
    int array[] = {1,2,3,4,5,6,7,8,9};
    int array2[] = {1,2,3,4,5,6,7,8,9,9999};
    int i = 9;
    int i2= 10;
    int counter = 0;


    while(counter < i ){
        printf("%d, ", array[counter]);
        ++counter;
    }
    printf("\n");
    counter = 0;
    while(counter < i2 ){
        printf("%d, ", array2[counter]);
        ++counter;
    }
    printf("\n");

    ft_rev_int_tab(array, i);
    ft_rev_int_tab(array2, i2);

    counter = 0;
    while(counter < i ){
        printf("%d, ", array[counter]);
        ++counter;
    }
    printf("\n");
    counter = 0;
    while(counter < i2 ){
        printf("%d, ", array2[counter]);
        ++counter;
    }
    printf("\n");


    return (0);
}