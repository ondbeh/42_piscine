/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:37:30 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/14 15:28:53 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnumeric(char c)
{
	if (c <= 47 || c >= 58)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	ret_int;
	int	is_positive;
	int	digit;

	is_positive = 1;
	ret_int = 0;
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!ft_isnumeric(*str))
			return (-1);
		digit = *str - '0';
		ret_int *= 10;
		ret_int += digit;
		++str;
	}
	return (ret_int);
}
