/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:31:08 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/13 14:41:19 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Prototype for the ft_sort_string_tab function
void ft_sort_string_tab(char **tab);

int main() {
    // Define an array of strings (null-terminated)
    char *tab[] = {
        "apple",
        "5646orange",
        "+banana",
        "*grape",
		NULL,
        "\\pineapple",
        "*kiwi",
        NULL
    };

    // Print the array before sorting
    printf("Before sorting:\n");
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }

    // Call the ft_sort_string_tab function to sort the array
    ft_sort_string_tab(tab);

    // Print the array after sorting
    printf("\nAfter sorting:\n");
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }

    return 0;
}
