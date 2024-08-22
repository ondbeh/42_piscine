/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:24:43 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/18 00:11:22 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

int	ft_rec_am(char **split_file)
{
	int	i;

	i = 0;
	while (*split_file)
	{
		i++;
		split_file++;
	}
	return (i);
}

char	*ft_get_key(char *str)
{
	char	*ret_str;
	char	*tmp_ptr;
	int		key_length;

	key_length = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (str[key_length] <= '9' && str[key_length] >= '0')
		key_length++;
	if (key_length == 0 && *str != '-')
		return (ft_return_zero());
	ret_str = malloc(sizeof(char) * (key_length + 1));
	if (!ret_str)
		return (NULL);
	tmp_ptr = ret_str;
	while (key_length--)
	{
		*tmp_ptr = *str;
		tmp_ptr++;
		str++;
	}
	*tmp_ptr = '\0';
	return (ret_str);
}

char	*ft_get_name_start(char *str)
{
	while (*str != ':' && *str)
		str++;
	if (!*str)
		return (NULL);
	str++;
	while (*str == ' ')
		str++;
	return (str);
}

char	*ft_get_name(char *str)
{
	char	*ret_str;
	char	*tmp_ptr;
	int		name_length;

	name_length = 0;
	str = ft_get_name_start(str);
	if (!str)
		return (NULL);
	while (str[name_length])
		name_length++;
	while (str[name_length] == ' ' && name_length > 0)
		name_length--;
	ret_str = malloc(sizeof(char) * (name_length + 1));
	if (!ret_str)
		return (NULL);
	tmp_ptr = ret_str;
	while (name_length--)
	{
		*tmp_ptr = *str;
		tmp_ptr++;
		str++;
	}
	*tmp_ptr = '\0';
	return (ret_str);
}

t_dict_record	*ft_build_dict(char **split_file)
{
	t_dict_record	*curr_record;
	t_dict_record	*dictionary;

	if (!split_file)
		return (NULL);
	dictionary = malloc(sizeof(t_dict_record) * (ft_rec_am(split_file) + 1));
	if (!dictionary)
		return (NULL);
	curr_record = dictionary;
	while (*split_file)
	{
		curr_record->key = ft_get_key(*split_file);
		curr_record->name = ft_get_name(*split_file);
		if (!curr_record->key || !curr_record->name)
		{
			ft_kill_dictionary(dictionary);
			return (NULL);
		}
		split_file++;
		curr_record++;
	}
	curr_record->key = NULL;
	curr_record->name = NULL;
	return (dictionary);
}
