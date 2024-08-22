/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:32:48 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/17 23:48:15 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

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

int	ft_strlen(const char *str)
{
	int	strlen;

	strlen = 0;
	while (*str)
	{
		++strlen;
		++str;
	}
	return (strlen);
}

t_dict_record	*ft_kill_dictionary(t_dict_record *dictionary)
{
	t_dict_record	*tmp_ptr;

	if (!dictionary)
		return (NULL);
	tmp_ptr = dictionary;
	while (tmp_ptr->key && tmp_ptr->name)
	{
		free (tmp_ptr->key);
		free (tmp_ptr->name);
		tmp_ptr++;
	}
	free (dictionary);
	return (NULL);
}

char	*ft_return_zero(void)
{
	char	*ret_ptr;

	ret_ptr = malloc(sizeof(char) * 2);
	if (!ret_ptr)
		return (NULL);
	ret_ptr[0] = '0';
	ret_ptr[1] = '\0';
	return (ret_ptr);
}
