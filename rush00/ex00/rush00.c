/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:31:14 by dreimann          #+#    #+#             */
/*   Updated: 2024/08/22 15:38:57 by obehavka         ###   ########.fr       */
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
			if ((cx == 1 && cy == 1) || (cx == x && cy == y))
				ft_putchar('o');
			else if ((cx == 1 && cy == y) || (cx == x && cy == 1))
				ft_putchar('o');
			else if (cy == 1 || cy == y)
				ft_putchar('-');
			else if (cx == 1 || cx == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			++cx;
		}
		ft_putchar('\n');
		cx = 1;
		++cy;
	}
}
