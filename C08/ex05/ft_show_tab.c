/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:15:04 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/09 11:58:07 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putdigit(int intdigit)
{
	char	c;

	if (intdigit < 0)
		intdigit = 0 - intdigit;
	c = '0' + intdigit;
	ft_putchar(c);
}

void	ft_putnbr(int nb)
{
	int	number_array[11];
	int	position;

	position = 1;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
		number_array[0] = 1;
	else
		number_array[0] = 0;
	while (nb != 0)
	{
		number_array[position] = nb % 10;
		nb = nb / 10;
		++position;
	}
	--position;
	if (number_array[0])
		ft_putchar('-');
	while (position > 0)
	{
		ft_putdigit (number_array[position]);
		--position;
	}
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putnbr(par->size);
		ft_putstr(par->copy);
		++par;
	}
}
