/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:00:37 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/21 11:25:51 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr_non_printable(char *str)
{
	char	hexnums[17];

	ft_strcpy(hexnums, "0123456789abcdef");
	while (*str)
	{
		if (*str <= 31 || *str >= 127)
		{
			write(1, "\\", 1);
			write(1, &hexnums[*str / 16], 1);
			write(1, &hexnums[*str % 16], 1);
		}
		else
		{
			write(1, str, 1);
		}
		++str;
	}
}
