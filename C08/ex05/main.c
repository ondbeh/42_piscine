#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

// Assuming these helper functions are already defined.
void ft_putstr(char *str);
void ft_putnbr(int nbr);
int ft_strlen(char *str);
char *ft_strcpy(char *dest, char *src);
void ft_kill(struct s_stock_str *par);

// Function prototypes for the given functions
void ft_show_tab(struct s_stock_str *par);
struct s_stock_str *ft_strs_to_tab(int ac, char **av);

int main(void)
{
    // Step 1: Define an array of strings
    char *arr[] = {
        "Hello",
        "world",
        "this",
        "is",
        "a",
        "test",
        NULL, 
        "end"
    };

    // Step 2: Convert these strings to t_stock_str array
    int arr_size = 6; // Number of strings in arr
    struct s_stock_str *result = ft_strs_to_tab(arr_size, arr);

    // Check if the conversion was successful
    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Show the contents of the resulting struct array
    ft_show_tab(result);

    // Step 4: Clean up (free) the memory allocated by ft_strs_to_tab
    ft_kill(result);

    return 0;
}