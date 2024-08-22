/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:24:29 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/22 12:14:13 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_ret_zero(char *base)
{
	char	*ret_ptr;

	ret_ptr = malloc (2);
	if (!ret_ptr)
		return (NULL);
	ret_ptr[0] = base[0];
	ret_ptr[1] = '\0';
	return (ret_ptr);
}

char	*ft_nbr_in_base(int dig_arr[50], char *base, int arr_size, int is_neg)
{
	char	*ret_str;
	char	*tmp_ptr;

	ret_str = malloc (arr_size + 2);
	if (!ret_str)
		return (NULL);
	tmp_ptr = ret_str;
	if (is_neg)
	{
		*tmp_ptr = '-';
		tmp_ptr++;
	}
	while (arr_size)
	{
		*tmp_ptr = base[dig_arr[arr_size - 1]];
		tmp_ptr++;
		arr_size--;
	}
	*tmp_ptr = '\0';
	return (ret_str);
}

char	*ft_putnbr_base(int nbr, int base_size, char *base)
{
	int	nbr_array[50];
	int	array_position;
	int	digit;
	int	is_negative;

	if (nbr < 0)
		is_negative = 1;
	else
		is_negative = 0;
	array_position = 0;
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
	return (ft_nbr_in_base(nbr_array, base, array_position, is_negative));
}
