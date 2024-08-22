/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:03:06 by dreimann          #+#    #+#             */
/*   Updated: 2024/08/22 15:39:23 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cy = 1;
	cx = 1;
	while (y >= cy && x > 0)
	{
		while (x >= cx)
		{
			if (cx == 1 && cy == 1)
				ft_putchar('A');
			else if ((cx == 1 && cy == y) || (cx == x && cy == 1))
				ft_putchar('C');
			else if (cx == x && cy == y)
				ft_putchar('A');
			else if (cx == 1 || cy == 1 || cx == x || cy == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			++cx;
		}
		ft_putchar('\n');
		cx = 1;
		++cy;
	}
}
