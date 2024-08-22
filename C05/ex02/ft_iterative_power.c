/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:42:49 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/07 11:46:36 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret_num;

	ret_num = 1;
	if (power < 0)
		return (0);
	while (power--)
		ret_num *= nb;
	return (ret_num);
}
