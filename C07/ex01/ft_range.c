/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:20:16 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/08 14:36:17 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	size;
	int				*ret_ptr;
	int				*tmp_ret_ptr;

	if (min >= max)
		return (NULL);
	size = max - min;
	ret_ptr = (int *)malloc (sizeof (int) * size);
	if (ret_ptr == NULL)
		return (NULL);
	tmp_ret_ptr = ret_ptr;
	while (min < max)
	{
		*tmp_ret_ptr = min++;
		++tmp_ret_ptr;
	}
	return (ret_ptr);
}
