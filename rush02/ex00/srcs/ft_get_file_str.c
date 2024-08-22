/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:25:58 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/17 21:49:48 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

int	ft_get_size(char *filename)
{
	int		file_descriptor;
	int		ret_value;
	int		currently_read;
	char	buffer[BUF_SIZE];

	ret_value = 0;
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (file_descriptor);
	currently_read = read(file_descriptor, buffer, BUF_SIZE);
	while (currently_read > 0)
	{
		ret_value += currently_read;
		currently_read = read(file_descriptor, buffer, BUF_SIZE);
	}
	close (file_descriptor);
	return (ret_value);
}

char	*ft_get_file_str(char *filename)
{
	int		file_descriptor;
	int		size;
	int		read_check;
	char	*ret_str;

	size = ft_get_size(filename);
	if (size <= 1)
		return (NULL);
	ret_str = (char *)malloc(size + 1);
	if (!ret_str)
		return (NULL);
	file_descriptor = open (filename, O_RDONLY);
	read_check = read (file_descriptor, ret_str, size);
	if (read_check == -1)
	{
		free (ret_str);
		close (file_descriptor);
		return (NULL);
	}
	close (file_descriptor);
	ret_str[size] = '\0';
	return (ret_str);
}
