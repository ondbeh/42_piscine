/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:28 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/20 11:45:44 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_add_link(t_link **link)
{
	(*link)->next = ft_new_link((*link)->pos + 1);
	*link = (*link)->next;
}

void	ft_display_hex_pos(int pos, int last_pos, int c_flag, int new_line)
{
	char	pos_array[9];
	char	hex_nbr[17];
	int		i;

	if (c_flag == 1)
		i = 6;
	else
		i = 5;
	ft_strcpy(hex_nbr, "0123456789abcdef");
	pos_array[i + 1] = hex_nbr[last_pos];
	pos_array[i + 2] = '\0';
	while (i >= 0)
	{
		pos_array[i--] = hex_nbr[pos % 16];
		pos /= 16;
	}
	ft_putstr(pos_array);
	if (new_line)
		write (1, "\n", 1);
	else if (c_flag == 0)
		write(1, " ", 1);
	else if (c_flag == 1)
		write(1, "  ", 2);
}

void	ft_dump_line(t_link *link, int c_flag)
{
	int		i;
	char	hex_nbr[17];

	i = 0;
	ft_strcpy(hex_nbr, "0123456789abcdef");
	while (i < 16)
	{
		write (1, &hex_nbr[link->hex[i] / 16], 1);
		write (1, &hex_nbr[link->hex[i] % 16], 1);
		if (i == 7 && c_flag)
			write (1, "  ", 2);
		else if (i < 15)
			write (1, " ", 1);
		i++;
	}
	i = 0;
}

void	ft_dump_rest(t_link *last_link, int c_flag, int last_pos)
{
	int	i;
	char	hex_nbr[17];

	i = 0;
	if (last_pos == 0)
		return (ft_display_hex_pos(last_link->pos, 0, c_flag, 1));
	ft_display_hex_pos(last_link->pos, 0, c_flag, 0);
	ft_strcpy(hex_nbr, "0123456789abcdef");
	while (i < 16)
	{
		if (i < last_pos)
		{
			write (1, &hex_nbr[last_link->hex[i] / 16], 1);
			write (1, &hex_nbr[last_link->hex[i] % 16], 1);
			if (i == 7 && c_flag)
				write (1, "  ", 2);
			else if (i < last_pos - 1)
				write (1, " ", 1);
		}
		else
		{
			write (1, "   ", 3);
			if (i == 7 && c_flag)
				write (1, " ", 1);
		}
		i++;
	}
	if (c_flag)
	{
		i = 0;
		write (1, "  |", 3);
		while (i < last_pos)
		{
			if (ft_str_is_printable((last_link->hex)[i]))
				write (1, &last_link->hex[i], 1);
			else
				write (1, ".", 1);
			i++;
		}
		write (1, "|", 1);
	}
	write (1, "\n", 1);
	return (ft_display_hex_pos(last_link->pos, last_pos, c_flag, 1));
}

void	ft_dump(t_link *link, int c_flag, int curr_pos)
{
	int		i;

	i = 0;
	while (link && link->next)
	{
		ft_display_hex_pos(link->pos, 0, c_flag, 0);
		ft_dump_line(link, c_flag);
		if (c_flag)
		{
			write (1, "  |", 3);
			while (i < 16)
			{
				if (ft_str_is_printable((link->hex)[i]))
					write (1, &link->hex[i], 1);
				else
					write (1, ".", 1);
				i++;
			}
			write (1, "|", 1);
		}
		link = link->next;
		i = 0;
		write (1, "\n", 1);
	}
	ft_dump_rest (link, c_flag, curr_pos);
}

int	file_hexdump(char *file_name, t_link **link, int *curr_pos)
{
	int	fd;
	int	currently_read;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (print_error(file_name, errno));
	currently_read = read(fd, &(*link)->hex[*curr_pos], 16 - *curr_pos);
	if (currently_read == -1)
		return (print_error(file_name, errno));
	currently_read += *curr_pos;
	while (currently_read != 0)
	{
		if (currently_read == -1)
			return (print_error(file_name, errno));
		if (currently_read == 16)
			ft_add_link(link);
		else
			return (*curr_pos = currently_read, 0);
		if (!(*link))
			return (print_error(file_name, errno));
		currently_read = read(fd, (*link)->hex, 16);
	}
	return (0);
}



int	main(int argc, char **argv)
{
	int		c_flag;
	int		i;
	int		ret_value;
	t_link	*list;
	t_link	*curr_link;
	int		hex_curr_pos;

	list = ft_new_link(0);
	if (!list)
		return (print_error("malloc", errno));
	curr_link = list;
	ret_value = 0;
	c_flag = 0;
	hex_curr_pos = 0;
	if (argc == 1)
		return (0);
		//return (command_line_hexdump(c_flag));
	if (ft_strcmp(argv[1], "-C") == 0)
	{
		c_flag = 1;
		if (argc == 2)
			return (0);
			//return (command_line_hexdump(c_flag));
		else
		{
			i = 2;
			while (i < argc)
				ret_value += file_hexdump(argv[i++], &curr_link, &hex_curr_pos);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
			ret_value += file_hexdump(argv[i++], &curr_link, &hex_curr_pos);
	}
	ft_dump(list, c_flag, hex_curr_pos);
	return (ret_value);
}
