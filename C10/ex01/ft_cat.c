/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:25:58 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/19 11:24:46 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 29000

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *c1, char *c2);

int	print_error(char *file_name, int v_errno)
{
	ft_putstr("cat: ");
	ft_putstr(file_name);
	ft_putstr(": ");
	ft_putstr(strerror(v_errno));
	ft_putstr("\n");
	return (1);
}

int	ft_read_standard_input(void)
{
	char	c[BUFFER_SIZE];
	int		read_size;

	read_size = BUFFER_SIZE;
	read_size = read(STDIN_FILENO, c, read_size);
	while (read_size != 0)
	{
		if (read_size == -1)
			return (print_error("-", errno));
		if (write (1, c, read_size) == -1)
			return (print_error("write", errno));
		read_size = read(STDIN_FILENO, c, BUFFER_SIZE);
	}
	return (0);
}

int	ft_read_file_input(int fd, char *file_name)
{
	char	c[BUFFER_SIZE];
	int		read_size;

	read_size = BUFFER_SIZE;
	read_size = read(fd, c, read_size);
	while (read_size != 0)
	{
		if (read_size == -1)
			return (print_error(file_name, errno));
		if (write (1, c, read_size) == -1)
			return (print_error("write", errno));
		read_size = read(fd, c, BUFFER_SIZE);
	}
	return (0);
}

int	ft_read_input(char *file_name)
{
	int	fd;
	int	ret_value;

	if (!ft_strcmp(file_name, "-"))
		return (ft_read_standard_input());
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (print_error(file_name, errno));
	else
	{
		ret_value = ft_read_file_input(fd, file_name);
		close (fd);
		return (ret_value);
	}
}

int	main(int argc, char **argv)
{
	int	ret_value;

	ret_value = 0;
	if (argc <= 1)
		ret_value += ft_read_standard_input();
	while (--argc)
		ret_value += ft_read_input(*(++argv));
	return (ret_value);
}
