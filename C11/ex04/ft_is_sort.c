/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:00:48 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/13 22:48:15 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	flag;
	int	ret;

	index = 1;
	flag = 0;
	while (index < length)
	{
		ret = (*f)(tab[index - 1], tab[index]);
		if (!flag && ret)
		{
			if (ret > 0)
				flag = 1;
			if (ret < 0)
				flag = -1;
		}
		if ((ret < 0 && flag > 0) || (ret > 0 && flag < 0))
		{
			return (0);
		}
		++index;
	}
	return (1);
}
