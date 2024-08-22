/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:35:45 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/18 00:33:12 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

char	*ft_get_str_from_key(char *key, t_dict_record *dict)
{
	while (dict->key)
	{
		if (!ft_strcmp(dict->key, key))
			return (dict->name);
		dict++;
	}
	return (NULL);
}

void	ft_print_key(char *key, int space_flag, t_dict_record *dict)
{
	int		strlen;
	char	*nbr_str;

	if (space_flag)
		write(1, " ", 1);
	nbr_str = ft_get_str_from_key(key, dict);
	strlen = ft_strlen(nbr_str);
	write(1, nbr_str, strlen);
}

void	ft_print_digit(char c, int space_flag, t_dict_record *dict)
{
	char	digits[2];

	if (c == '0')
		return ;
	digits[0] = c;
	digits[1] = '\0';
	ft_print_key(digits, space_flag, dict);
}
