/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:00:53 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/07 20:31:46 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putdigit(int intdigit)
{
	char	c;

	if (intdigit < 0)
		intdigit = 0 - intdigit;
	c = '0' + intdigit;
	write(1, &c, 1);
}

int	ft_is_valid_move(int board[10][10], int column, int row)
{
	int	i;

	i = 1;
	while (column - i >= 0)
	{
		if (board[column - i][row])
			return (0);
		++i;
	}
	i = 1;
	while (column - i >= 0 && row - i >= 0)
	{
		if (board[column - i][row - i])
			return (0);
		++i;
	}
	i = 1;
	while (column - i >= 0 && row + i <= 9)
	{
		if (board[column - i][row + i])
			return (0);
		++i;
	}
	return (1);
}

void	ft_print_board(int board[10][10])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			if (board[i][j])
				ft_putdigit(j);
			++j;
		}
		j = 0;
		++i;
	}
	write(1, "\n", 1);
}

int	ft_board_solver(int curr_column, int board[10][10])
{
	int	position;
	int	ret_value;

	position = 0;
	ret_value = 0;
	if (curr_column == 10)
	{
		ft_print_board(board);
		return (1);
	}
	while (position < 10)
	{
		if (ft_is_valid_move(board, curr_column, position))
		{
			board[curr_column][position] = 1;
			ret_value += ft_board_solver(curr_column + 1, board);
			board[curr_column][position] = 0;
		}
		++position;
	}
	return (ret_value);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	result;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			board[i][j] = 0;
			++j;
		}
		j = 0;
		++i;
	}
	result = ft_board_solver(0, board);
	return (result);
}
