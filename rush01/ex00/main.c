/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:26:28 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/10 15:22:07 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	board_solver(int board[4][4], int rules[16], int curr_row, int curr_column);
int	ft_is_legal_input(int argc, char *argv, int *rules);

void	build_board(int **board, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			board[x][y] = 0;
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	int	rules[16];
	int	board[4][4];
	int	*board_ptr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		board_ptr[i] = board[i];
		i++;
	}
	build_board(board_ptr, 4, 4);
	if (!ft_is_legal_input(argc, argv[1], rules))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!board_solver(board, rules, 0, 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
