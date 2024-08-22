/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:43:11 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/19 11:29:26 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 29000

int	main(int argc, char **argv)
{
	int		file;
	char	c[BUFFER_SIZE];

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		file = open(argv[1], O_RDONLY);
		if (file < 0)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		while (read(file, c, BUFFER_SIZE))
			write(1, c, BUFFER_SIZE);
		close (file);
	}
	return (0);
}
