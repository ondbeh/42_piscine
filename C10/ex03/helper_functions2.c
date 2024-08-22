/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:33:52 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/19 21:00:13 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putstr_error(const char *str)
{
	while (*str != '\0')
	{
		write (2, str, 1);
		++str;
	}
}

int	print_error(char *file_name, int v_errno)
{
	ft_putstr_error("hexdump: ");
	ft_putstr_error(file_name);
	ft_putstr_error(": ");
	ft_putstr_error(strerror(v_errno));
	ft_putstr_error("\n");
	return (1);
}

t_link	*ft_new_link(int pos)
{
	t_link	*ret_ptr;

	ret_ptr = malloc (sizeof(t_link));
	if (!ret_ptr)
		return (NULL);
	ret_ptr->pos = pos;
	ret_ptr->next = NULL;
	return (ret_ptr);
}

int	ft_str_is_printable(char c)
{
	if (c <= 31 || c >= 127)
		return (0);
	else
		return (1);
}
