/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:59:06 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/22 14:27:25 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puttwodigits(int nb)
{
	ft_putchar((char)(nb / 10 + '0'));
	ft_putchar((char)(nb % 10 + '0'));
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_puttwodigits(i);
			ft_putchar(' ');
			ft_puttwodigits(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
