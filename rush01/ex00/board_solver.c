/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:00:46 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/09 23:54:48 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_solution(int board[4][4], int rules[16]);

int	is_valid_move(int board[4][4], int curr_row, int curr_column, int value)
{
	int	i;

	i = 1;
	while (curr_column - i >= 0)
	{
		if (board[curr_row][curr_column - i] == value)
			return (0);
		++i;
	}
	i = 1;
	while (curr_row - i >= 0)
	{
		if (board[curr_row - i][curr_column] == value)
			return (0);
		++i;
	}
	return (1);
}

void	print_board(int board[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			c = board[i][j] + '1';
			write(1, &c, 1);
			if (j == 3)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			++j;
		}
		j = 0;
		++i;
	}
}

int	board_solver(int board[4][4], int rules[16], int curr_row, int curr_column)
{
	int	solved;
	int	curr_value;

	solved = 0;
	curr_value = 0;
	if (curr_row == 4)
	{
		solved = is_valid_solution(board, rules);
		if (solved)
			print_board(board);
		return (solved);
	}
	while (curr_value < 4 && !solved)
	{
		if (is_valid_move(board, curr_row, curr_column, curr_value))
		{
			board[curr_row][curr_column] = curr_value;
			if (curr_column < 3)
				solved = board_solver(board, rules, curr_row, curr_column + 1);
			else
				solved = board_solver(board, rules, curr_row + 1, 0);
		}
		++curr_value;
	}
	return (solved);
}
