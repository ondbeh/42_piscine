/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:34:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/15 21:53:42 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_putstr(char *str);
void	ft_put3str(char *a, char *b, char *c);
int		ft_atoi(char *str);
int		ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
void	ft_put3str_error(char *a, char *b, char *c);

void	display_header(char *filename, int flag)
{
	if (!flag)
		return ;
	ft_put3str("==> ", filename, " <==\n");
}

void	print_tail(char *pri_arr, char *sec_arr, int size, int in_pri)
{
	int	i;

	i = in_pri;
	if (sec_arr[size] != 'X')
	{
		while (i < size)
			write (1, &sec_arr[i++], 1);
	}
	i = 0;
	while (i < in_pri)
		write (1, &pri_arr[i++], 1);
}

void	ft_clean_up(char *ptr1, char *ptr2, int fd)
{
	free (ptr1);
	free (ptr2);
	close (fd);
}

int	ft_setup(char *filename, char **arr0_ptr, char **arr1_ptr, int size)
{
	int	fd;

	if (!ft_strcmp(filename, ""))
		fd = 0;
	else
		fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_put3str_error("tail: ", filename, "");
		ft_put3str_error(": ", strerror(errno), "\n");
		return (-1);
	}
	if (size == 0)
		return (-2);
	*arr0_ptr = malloc (size + 1);
	*arr1_ptr = malloc (size + 1);
	if (!(*arr0_ptr) || !(*arr1_ptr))
	{
		ft_put3str_error("tail: ", strerror(errno), "\n");
		ft_clean_up(*arr0_ptr, *arr1_ptr, fd);
		return (-1);
	}
	(*arr0_ptr)[size] = '\0';
	(*arr1_ptr)[size] = 'X';
	return (fd);
}

int	ft_read(int amount, int header_flag, char *filename, int index)
{
	int		bytes_read;
	int		fd;
	char	*array0;
	char	*array1;

	fd = ft_setup(filename, &array0, &array1, amount);
	if (fd != -1)
		display_header(filename, header_flag);
	if (fd == -1 || fd == -2)
		return (fd + 2);
	bytes_read = read(fd, array0, amount);
	while (bytes_read == amount)
	{
		ft_strcpy(array1, array0);
		bytes_read = read(fd, array0, amount);
	}
	print_tail(array0, array1, amount, bytes_read);
	if (header_flag != index)
		ft_putstr("\n");
	ft_clean_up(array0, array1, fd);
	return (0);
}
