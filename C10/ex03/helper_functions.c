/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:02:41 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/19 18:17:53 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

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

void	ft_putstr(const char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		++str;
	}
}

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
