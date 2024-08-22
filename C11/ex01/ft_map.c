/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:31:43 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/12 22:37:27 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ret_ptr;
	int	*tmp_ret;

	ret_ptr = malloc (sizeof(int) * length);
	if (!ret_ptr)
		return (NULL);
	tmp_ret = ret_ptr;
	while (length--)
	{
		*tmp_ret = (*f)(*tab);
		++tmp_ret;
		++tab;
	}
	return (ret_ptr);
}
