#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main() {
    int tab[] = {64};
    int size = sizeof(tab) / sizeof(tab[0]);
    int i;
    
    printf("Original array: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    ft_sort_int_tab(tab, size);

    printf("Sorted array: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}