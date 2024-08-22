/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:27:40 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/10 10:06:50 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	strlen;

	if (str == NULL)
		return (0);
	strlen = 0;
	while (*str != '\0')
	{
		++strlen;
		++str;
	}
	return (strlen);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = *src;
	return (tmp);
}

void	ft_kill(struct s_stock_str *structure)
{
	struct s_stock_str	*tmp_structure;

	tmp_structure = structure;
	while (tmp_structure->str)
	{
		free (tmp_structure->copy);
		++tmp_structure;
	}
	free (structure);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret_struct;
	struct s_stock_str	*tmp_ptr;

	ret_struct = malloc (sizeof (struct s_stock_str) * (ac + 1));
	if (!ret_struct)
		return (NULL);
	tmp_ptr = ret_struct;
	while (ac && *av)
	{
		tmp_ptr->size = ft_strlen(*av);
		tmp_ptr->copy = malloc ((tmp_ptr->size + 1) * sizeof (char));
		if (!tmp_ptr->copy)
		{
			ft_kill(ret_struct);
			return (NULL);
		}
		ft_strcpy (tmp_ptr->copy, *av);
		tmp_ptr->str = *av;
		++av;
		--ac;
		++tmp_ptr;
	}
	tmp_ptr->str = NULL;
	return (ret_struct);
}
