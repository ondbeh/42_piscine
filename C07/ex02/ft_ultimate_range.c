/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:46:53 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/08 14:55:23 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	size;
	int				*ret_ptr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	ret_ptr = (int *)malloc (sizeof (int) * size);
	if (ret_ptr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = ret_ptr;
	while (min < max)
	{
		*ret_ptr = min++;
		++ret_ptr;
	}
	return (size);
}
