/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:28:35 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/13 13:52:03 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	int	number_array[22];
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
}
