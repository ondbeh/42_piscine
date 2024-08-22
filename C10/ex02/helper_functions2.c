/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:33:52 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/15 16:58:52 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_error(const char *str)
{
	while (*str != '\0')
	{
		write (2, str, 1);
		++str;
	}
}

void	ft_put3str_error(char *a, char *b, char *c)
{
	ft_putstr_error(a);
	ft_putstr_error(b);
	ft_putstr_error(c);
}
