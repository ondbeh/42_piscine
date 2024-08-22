/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:42:46 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/13 14:44:53 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_arr_size(char **tab)
{
	int	size;

	size = 0;
	while (*tab)
	{
		++size;
		++tab;
	}
	return (size);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		tab_size;
	char	*tmp;

	i = 0;
	tab_size = ft_arr_size(tab);
	while (i < tab_size - 1)
	{
		j = 0;
		while (j < tab_size - (i + 1))
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}
