/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:26:31 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/18 00:19:58 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

int	error_msg(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
	write(1, "\n", 1);
	return (1);
}

int	ft_validate_input(char *str)
{
	int	i;

	i = 0;
	if (*str == '+')
		str++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		else if (i > 38)
			return (-2);
		i++;
	}
	return (0);
}

void	ft_clean_up(char *str, char **split, t_dict_record *dict)
{
	free (str);
	ft_kill_split_string(split);
	ft_kill_dictionary(dict);
}

int	ft_do(char *dict_file, char *nbr_str)
{
	char			*file_str;
	char			**split_file;
	t_dict_record	*dictionary;

	if (ft_validate_input(nbr_str) == -1)
		return (error_msg("Error"));
	else if (ft_validate_input(nbr_str) == -2)
		return (error_msg("Dict Error"));
	file_str = ft_get_file_str(dict_file);
	split_file = ft_split(file_str, "\n");
	dictionary = ft_build_dict(split_file);
	if (!dictionary)
	{
		ft_clean_up(file_str, split_file, dictionary);
		return (error_msg("Dict Error"));
	}
	ft_print_nbr(nbr_str, dictionary, 0);
	write(1, "\n", 1);
	ft_clean_up(file_str, split_file, dictionary);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (error_msg("Error"));
	if (argc == 2)
		return (ft_do(DEF_DICT, argv[1]));
	else
		return (ft_do(argv[1], argv[2]));
}
