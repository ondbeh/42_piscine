/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:37:30 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/06 16:09:19 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

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
	while (ft_isspace (*str))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_positive *= (-1);
		++str;
	}
	while (ft_isnumeric (*str))
	{
		digit = *str - '0';
		ret_int *= 10;
		ret_int -= digit;
		++str;
	}
	return (ret_int * is_positive * (-1));
}
