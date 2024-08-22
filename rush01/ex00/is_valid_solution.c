/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:57:42 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/09 23:54:28 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	top_look(int board[4][4], int column)
{
	int	row;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	row = 0;
	while (row < 4)
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

int	bottom_look(int board[4][4], int column)
{
	int	row;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	row = 3;
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

int	left_look(int board[4][4], int row)
{
	int	column;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	column = 0;
	while (column < 4)
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

int	right_look(int board[4][4], int row)
{
	int	column;
	int	curr_highest;
	int	count;

	count = 0;
	curr_highest = -1;
	column = 3;
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

int	is_valid_solution(int board[4][4], int rules[16])
{
	int	pos;
	int	rules_index;

	rules_index = 0;
	pos = 0;
	while (pos < 4)
	{
		if (rules[rules_index] != top_look(board, pos))
			return (0);
		if (rules[4 + rules_index] != bottom_look(board, pos))
			return (0);
		if (rules[8 + rules_index] != left_look(board, pos))
			return (0);
		if (rules[12 + rules_index] != right_look(board, pos))
			return (0);
		++rules_index;
		++pos;
	}
	return (1);
}
