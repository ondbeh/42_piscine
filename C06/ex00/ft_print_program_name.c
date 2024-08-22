/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:44:35 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/07 20:49:43 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		++str;
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	ft_putstr(argv[0]);
	return (argc * 0);
}
