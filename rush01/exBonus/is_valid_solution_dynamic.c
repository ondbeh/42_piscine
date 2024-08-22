/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_solution_dynamic.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksinn <ksinn@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:14:11 by ksinn             #+#    #+#             */
/*   Updated: 2024/08/11 22:06:40 by ksinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	top_look_d(int **board, int column, int width)
{
	int	row;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	row = 0;
	while (row < width)
	{
		if (board[row][column] > curr_highest)
		{
			curr_highest = board[row][column];
			++count;
		}
		++row;
	}
	return (count);
}

int	bottom_look_d(int **board, int column, int width)
{
	int	row;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	row = width - 1;
	while (row >= 0)
	{
		if (board[row][column] > curr_highest)
		{
			curr_highest = board[row][column];
			++count;
		}
		--row;
	}
	return (count);
}

int	left_look_d(int **board, int row, int width)
{
	int	column;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	column = 0;
	while (column < width)
	{
		if (board[row][column] > curr_highest)
		{
			curr_highest = board[row][column];
			++count;
		}
		++column;
	}
	return (count);
}

int	right_look_d(int **board, int row, int width)
{
	int	column;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	column = width - 1;
	while (column >= 0)
	{
		if (board[row][column] > curr_highest)
		{
			curr_highest = board[row][column];
			++count;
		}
		--column;
	}
	return (count);
}

int	is_valid_solution_d(int **board, int *rules, int width)
{
	int	pos;
	int	rules_index;

	rules_index = 1;
	pos = 0;
	while (pos < width)
	{
		if (rules[rules_index] != top_look_d(board, pos, width))
			return (0);
		if (rules[width + rules_index] != bottom_look_d(board, pos, width))
			return (0);
		if (rules[2 * width + rules_index] != left_look_d(board, pos, width))
			return (0);
		if (rules[3 * width + rules_index] != right_look_d(board, pos, width))
			return (0);
		++rules_index;
		++pos;
	}
	return (1);
}
