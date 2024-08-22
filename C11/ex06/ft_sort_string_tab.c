/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:18:34 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/13 14:39:40 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	ret_value;

	ret_value = 0;
	while (*s1 != '\0' && *s2 != '\0')
	{
		ret_value = *s1 - *s2;
		if (ret_value != 0)
			return (ret_value);
		++s1;
		++s2;
	}
	ret_value = *s1 - *s2;
	return (ret_value);
}

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

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
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
