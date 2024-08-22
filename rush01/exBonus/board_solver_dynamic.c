/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_solver_dynamic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksinn <ksinn@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:07:15 by ksinn             #+#    #+#             */
/*   Updated: 2024/08/11 22:08:36 by ksinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_solution_d(int **board, int *rules, int width);

int	is_valid_move_d(int **board, int curr_row, int curr_column, int value)
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

void	print_board_d(int **board, int *rules)
{
	int		i;
	int		j;
	char	c;
	int		width;

	i = 0;
	j = 0;
	width = rules[0];
	while (i < width)
	{
		while (j < width)
		{
			c = board[i][j] + '1';
			write(1, &c, 1);
			if (j == width - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			++j;
		}
		j = 0;
		++i;
	}
}

int	board_solver_d(int **board, int *rules, int curr_row, int curr_col)
{
	int	solved;
	int	curr_value;

	solved = 0;
	curr_value = 0;
	if (curr_row == rules[0])
	{
		solved = is_valid_solution_d(board, rules, rules[0]);
		if (solved)
			print_board_d(board, rules);
		return (solved);
	}
	while (curr_value < rules[0] && !solved)
	{
		if (is_valid_move_d(board, curr_row, curr_col, curr_value))
		{
			board[curr_row][curr_col] = curr_value;
			if (curr_col < rules[0] - 1)
				solved = board_solver_d(board, rules, curr_row, curr_col + 1);
			else
				solved = board_solver_d(board, rules, curr_row + 1, 0);
		}
		++curr_value;
	}
	return (solved);
}
