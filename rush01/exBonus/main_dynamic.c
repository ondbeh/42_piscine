/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dynamic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksinn <ksinn@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:08:48 by ksinn             #+#    #+#             */
/*   Updated: 2024/08/11 22:24:58 by ksinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_is_legal_input_d(char *argv, int **rules, int width);
int	board_solver_d(int **board, int *rules, int curr_row, int curr_col);

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

int	**ft_malloc_board(int width)
{
	int	i;
	int	**board;

	board = (int **)malloc(width * 8);
	i = 0;
	while (i < width)
	{
		board[i] = (int *)malloc(width * 4);
		i++;
	}
	return (board);
}

int	ft_find_width(int argc, char **argv)
{
	int	width;

	if (argc != 2)
		return (-1);
	width = 0;
	while (argv[1][width])
		width++;
	width = (width + 1) / 8;
	if (width != 1 && width != 2 && width != 3 && width != 4 && width != 5
		&& width != 6 && width != 7 && width != 8 && width != 9)
		return (-1);
	return (width);
}

void	ft_free(int *rules, int **board, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		free(board[i]);
		i++;
	}
	free(board);
	free(rules);
}

int	main(int argc, char **argv)
{
	int	*rules;
	int	**board;

	if (ft_find_width(argc, argv) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	rules = NULL;
	board = ft_malloc_board(ft_find_width(argc, argv));
	if (board == NULL)
	{
		ft_free(rules, board, ft_find_width(argc, argv));
		return (0);
	}
	build_board(board, ft_find_width(argc, argv), ft_find_width(argc, argv));
	if ((!ft_is_legal_input_d(argv[1], &rules, ft_find_width(argc, argv)))
		|| (!board_solver_d(board, rules, 0, 0)))
	{
		ft_free(rules, board, ft_find_width(argc, argv));
		write(1, "Error\n", 6);
		return (0);
	}
	ft_free(rules, board, ft_find_width(argc, argv));
	return (0);
}
