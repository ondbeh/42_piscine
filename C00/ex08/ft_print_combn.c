/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:03 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/22 13:56:07 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	combination_recursion(int pos, int n, char *curr_str, int *print_before)
{
	int		i;
	char	j;

	i = 0;
	if (pos == n)
	{
		if (*print_before)
			write (1, ", ", 2);
		else
			*print_before = 1;
		while (i < n)
			write(1, &curr_str[i++], 1);
		return ;
	}
	j = curr_str[pos - 1] + 1;
	if (j == '9' && pos != n - 1)
		return ;
	while (j <= '9')
	{
		curr_str[pos] = j;
		combination_recursion(pos + 1, n, curr_str, print_before);
		j++;
	}
}

void	ft_print_combn(int n)
{
	char	curr_str[10];
	int		print_before;
	char	i;

	i = '0';
	print_before = 0;
	while (i <= '9')
	{
		curr_str[0] = i;
		combination_recursion(1, n, curr_str, &print_before);
		i++;
	}
}
