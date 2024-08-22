/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:28:57 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/07 11:47:07 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret_int;

	ret_int = 1;
	if (nb < 0)
		return (0);
	while (nb)
		ret_int *= nb--;
	return (ret_int);
}
