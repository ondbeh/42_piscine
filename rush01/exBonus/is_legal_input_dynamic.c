/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_legal_input_dynamic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksinn <ksinn@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:05:02 by ksinn             #+#    #+#             */
/*   Updated: 2024/08/12 00:21:28 by ksinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace_d(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_isvalid_box_d(char c, int width)
{
	if (c >= '1' && c <= ((char)width + '0'))
		return (1);
	return (0);
}

int	ft_check_alternating_d(int *flag, char c, int width)
{
	if (ft_isvalid_box_d(c, width))
	{
		if (*flag == 1)
			return (0);
		*flag = 1;
	}
	if (ft_isspace_d(c))
	{
		if (*flag == 0)
			return (0);
		*flag = 0;
	}
	return (1);
}

int	*ft_malloc_rules(int width)
{
	int	*rules;

	rules = (int *)malloc(width * 4 * 8 + 4);
	rules[0] = width;
	return (rules);
}

int	ft_is_legal_input_d(char *argv, int **rules, int width)
{
	int	i;
	int	nbr_args;
	int	flag;

	*rules = ft_malloc_rules(width);
	if (*rules == NULL)
		return (0);
	i = 0;
	nbr_args = 0;
	flag = 0;
	while (argv[i]
		&& (ft_isspace_d(argv[i]) || ft_isvalid_box_d(argv[i], width)))
	{
		if (nbr_args >= width * 4)
			return (0);
		if (!ft_check_alternating_d(&flag, argv[i], width))
			return (0);
		if (ft_isvalid_box_d(argv[i], width))
		{
			(*rules)[nbr_args + 1] = argv[i] - '0';
			nbr_args++;
		}
		i++;
	}
	return (nbr_args == width * 4);
}
