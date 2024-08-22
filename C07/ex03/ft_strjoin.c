/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:59:41 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/08 16:53:45 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*str != '\0')
	{
		++strlen;
		++str;
	}
	return (strlen);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	c_strl;

	if (!size)
		return (1);
	c_strl = ft_strlen(*strs);
	if (size == 1)
		return (c_strl + 1);
	return (ft_total_length(size - 1, ++strs, sep) + c_strl + ft_strlen(sep));
}

char	*ft_fill_it_up(char *curr_pos, char *str, char *sep, int size)
{
	while (*str)
	{
		*curr_pos = *str;
		++curr_pos;
		++(str);
	}
	while (*sep && size > 0)
	{
		*curr_pos = *sep;
		++curr_pos;
		++sep;
	}
	return (curr_pos);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	char	*ret_str;
	char	*ret_tmp;
	char	*sep_tmp;

	total_length = ft_total_length(size, strs, sep);
	ret_str = (char *)malloc (sizeof (char) * total_length);
	if (ret_str == NULL)
		return (NULL);
	ret_tmp = ret_str;
	sep_tmp = sep;
	while (size--)
	{
		ret_tmp = ft_fill_it_up(ret_tmp, *strs, sep, size);
		++strs;
	}
	*ret_tmp = '\0';
	return (ret_str);
}
