/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:20:03 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/15 16:38:58 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 29000

int		ft_atoi(char *str);
int		ft_read(int amount, int header_flag, char *filename, int index);
void	print_tail(char *pri_arr, char *sec_arr, int size, int in_pri);
char	*ft_strcpy(char *dest, char *src);
void	ft_put3str_error(char *a, char *b, char *c);
void	ft_putstr_error(const char *str);

char	*ft_smart_input(char *array_start, char *array, char *input, int size)
{
	while (*input)
	{
		if (array == &(array_start[size]))
			array = array_start;
		*array = *input;
		++array;
		++input;
	}
	return (array);
}

void	ft_smart_print(char *arr_start, char *arr_pos, int size, int bytes_read)
{
	char	*curr_pos;

	if (bytes_read > size)
	{
		curr_pos = arr_pos;
		while (curr_pos != &(arr_pos[size]))
		{
			write(1, curr_pos, 1);
			++curr_pos;
		}
	}
	curr_pos = arr_start;
	while (curr_pos != arr_pos)
	{
		write(1, curr_pos, 1);
		++curr_pos;
	}
}

int	ft_read_stdin(int amount)
{
	char	*array0;
	char	*array0_start;
	char	read_array[BUFFER_SIZE + 1];
	int		bytes_read_curr;
	int		bytes_read_total;

	array0 = malloc(amount);
	if (!array0)
		return (1);
	array0_start = array0;
	bytes_read_curr = read(STDIN_FILENO, read_array, BUFFER_SIZE);
	read_array[bytes_read_curr] = '\0';
	bytes_read_total = bytes_read_curr;
	while (bytes_read_curr > 0)
	{
		array0 = ft_smart_input(array0_start, array0, read_array, amount);
		bytes_read_curr = read(STDIN_FILENO, read_array, BUFFER_SIZE);
		read_array[bytes_read_curr] = '\0';
		bytes_read_total += bytes_read_curr;
	}
	ft_smart_print(array0_start, array0, amount, bytes_read_total);
	return (0);
}

int	ft_read_files(char **files, int argc, int amount)
{
	int	i;
	int	ret_int;

	ret_int = 0;
	i = 0;
	if (!argc)
		ft_read_stdin(amount);
	while (i < argc)
	{
		ret_int += ft_read(amount, argc - 1, files[i], i);
		++i;
	}
	return (ret_int);
}

int	main(int argc, char **argv)
{
	int	amount;
	int	ret_value;

	ret_value = 0;
	if (argc == 2)
	{
		ft_put3str_error("tail: option requires an argument -- c\n",
			"usage: tail [-F | -f | -r] [-q]",
			" [-b # | -c # | -n #] [file ...]\n");
		return (1);
	}
	amount = ft_atoi (argv[2]);
	if (amount == -1)
	{
		ft_put3str_error("tail: illegal offset -- ", argv[2], "\n");
		return (1);
	}
	ret_value = ft_read_files(&argv[3], argc - 3, amount);
	return (ret_value);
}
