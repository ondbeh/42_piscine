/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:58:01 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/06 22:06:39 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base_check(int *base_size, char *base)
{
	char	*curr_position;

	*base_size = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' || *base < 32 || *base > 126)
			return (0);
		curr_position = base + 1;
		while (*curr_position != '\0')
		{
			if (*base == *curr_position)
				return (0);
			++curr_position;
		}
		++(*base_size);
		++base;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;
	int	nbr_array[50];
	int	array_position;
	int	digit;

	array_position = 0;
	if (!ft_base_check(&base_size, base))
		return ;
	if (nbr == 0)
		ft_putchar(base[0]);
	if (nbr < 0)
		ft_putchar('-');
	while (nbr)
	{
		if (nbr < 0)
			digit = (-1) * (nbr % base_size);
		else
			digit = nbr % base_size;
		nbr_array[array_position] = digit;
		nbr /= base_size;
		++array_position;
	}
	while (array_position--)
		ft_putchar(base[nbr_array[array_position]]);
}
