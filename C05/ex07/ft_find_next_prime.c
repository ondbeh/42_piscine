/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:20:28 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/20 13:08:36 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	while (i < nb / i)
		++i;
	if (nb % i == 0 && i == nb / i)
		return (i);
	return (i - 1);
}

int	prime_solver(int curr_div, int nb)
{
	if (nb == curr_div || curr_div > ft_sqrt(nb))
		return (1);
	else if (nb % curr_div == 0)
		return (0);
	else
		return (prime_solver(curr_div + 2, nb));
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	else if (nb % 2 == 0)
		return (0);
	return (prime_solver(3, nb));
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
