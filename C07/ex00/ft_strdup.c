/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:31:49 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/08 12:49:45 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	char	*ret_str;
	char	*tmp_ret_str;

	if (src == NULL)
		return (NULL);
	ret_str = (char *)malloc (sizeof (char) * ft_strlen(src));
	if (ret_str == NULL)
		return (NULL);
	tmp_ret_str = ret_str;
	while (*src)
	{
		*tmp_ret_str = *src;
		++tmp_ret_str;
		++src;
	}
	*tmp_ret_str = '\0';
	return (ret_str);
}
