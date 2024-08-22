#include <stdio.h>

void ft_foreach(int *tab, int length, void (*f)(int));

// A sample function to be used with ft_foreach
void print_number(int n)
{
    printf("%d\n", n);
}

// Another example function that doubles the value (to demonstrate a different use case)
void double_number(int n)
{
    printf("%d\n", n * 2);
}

int main()
{
    // Test array
    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Testing ft_foreach with print_number:\n");
    ft_foreach(numbers, length, &print_number);

    printf("\nTesting ft_foreach with double_number:\n");
    ft_foreach(numbers, length, &double_number);

    return 0;
}