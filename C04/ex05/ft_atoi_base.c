/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:44:48 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/06 22:06:43 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_base_check(int *base_size, char *base)
{
	char	*curr_position;

	*base_size = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' || *base < 32 || *base > 126
			|| ft_isspace(*base))
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

int	ft_is_in_base(char c, char *base, int *position)
{
	*position = 0;
	while (*base != '\0')
	{
		if (*base == c)
		{
			return (1);
		}
		++base;
		++(*position);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ret_int;
	int	base_size;
	int	position;
	int	is_positive;

	is_positive = 1;
	ret_int = 0;
	if (!ft_base_check(&base_size, base))
		return (0);
	while (ft_isspace(*str))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_positive *= (-1);
		++str;
	}
	while (ft_is_in_base (*str, base, &position))
	{
		ret_int *= base_size;
		ret_int -= position;
		++str;
	}
	return (ret_int * is_positive * (-1));
}
