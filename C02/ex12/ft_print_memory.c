/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:23:17 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/21 11:26:13 by obehavka         ###   ########.fr       */
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

void	ft_print_address(void *ptr)
{
	char				hex_digits[17];
	char				address_str[16];
	unsigned long long	address;
	int					i;

	address = (unsigned long long)ptr;
	i = 16;
	ft_strcpy (hex_digits, "0123456789abcdef");
	while (i)
	{
		address_str[i - 1] = hex_digits[address % 16];
		address /= 16;
		i--;
	}
	write(1, address_str, 16);
	write(1, ": ", 2);
}

void	ft_put_printable_line(void *addr, int rem_len)
{
	int		i;
	char	*c;

	c = (char *)addr;
	i = 0;
	while (i < 16 && i < rem_len)
	{
		if (c[i] <= 31 || c[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &c[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

void	ft_hexprint(void *addr)
{
	char	hex_digits[17];
	char	*c;

	c = (char *)addr;
	ft_strcpy (hex_digits, "0123456789abcdef");
	write(1, &hex_digits[*c / 16], 1);
	write(1, &hex_digits[*c % 16], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	if (size == 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		ft_print_address(addr + i);
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
				ft_hexprint(addr + i + j);
			else
				write (1, "  ", 2);
			if (j % 2 == 1)
				write(1, " ", 1);
			j++;
		}
		ft_put_printable_line(addr + i, size - i);
		i += 16;
	}
	return (addr);
}
