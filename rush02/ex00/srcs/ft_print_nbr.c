/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:34:22 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/18 00:33:11 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

int	print_hundreds(char *nbr_string, t_dict_record *dict, int *space_flag)
{
	char	tens[3];

	if (*nbr_string != '0')
	{
		ft_print_digit(*nbr_string, *space_flag, dict);
		ft_print_key("100", 1, dict);
		*space_flag = 1;
	}
	else if (nbr_string[1] == '0' && nbr_string[2] == '0')
		return (0);
	if (nbr_string[1] == '1')
		ft_print_key(&(nbr_string[1]), *space_flag, dict);
	else if (nbr_string[1] == '0')
		ft_print_digit(nbr_string[2], *space_flag, dict);
	else
	{
		tens[0] = nbr_string[1];
		tens[1] = '0';
		tens[2] = '\0';
		ft_print_key(tens, *space_flag, dict);
		ft_print_digit(nbr_string[2], 1, dict);
	}
	*space_flag = 1;
	return (1);
}

void	ft_setup_curr_hund(char *nbr_str, char (*curr_hundreds)[4])
{
	int	digits_in_curr_hunds;

	digits_in_curr_hunds = ft_strlen(nbr_str) % 3;
	(*curr_hundreds)[0] = '0';
	(*curr_hundreds)[1] = '0';
	(*curr_hundreds)[2] = '0';
	(*curr_hundreds)[3] = '\0';
	if (digits_in_curr_hunds == 0)
	{
		(*curr_hundreds)[0] = nbr_str[0];
		(*curr_hundreds)[1] = nbr_str[1];
		(*curr_hundreds)[2] = nbr_str[2];
	}
	else if (digits_in_curr_hunds == 2)
	{
		(*curr_hundreds)[1] = nbr_str[0];
		(*curr_hundreds)[2] = nbr_str[1];
	}
	else
		(*curr_hundreds)[2] = nbr_str[0];
}

void	print_curr_th_pow(char *nbr_string, t_dict_record *dict)
{
	char	key[MAX_NUM_SIZE];
	int		actual_num_size;
	int		curr_h_size;
	int		i;

	i = 1;
	actual_num_size = ft_strlen(nbr_string);
	curr_h_size = actual_num_size % 3;
	if (curr_h_size == 0)
		curr_h_size += 3;
	actual_num_size -= curr_h_size;
	if (actual_num_size == 0)
		return ;
	key[0] = '1';
	while (i <= actual_num_size)
		key[i++] = '0';
	key[i] = '\0';
	ft_print_key(key, 1, dict);
}

void	ft_print_nbr(char *nbr_str, t_dict_record *dict, int flag)
{
	char	curr_hundreds[4];
	int		digits_in_curr_hunds;

	digits_in_curr_hunds = ft_strlen(nbr_str) % 3;
	if (!digits_in_curr_hunds)
		digits_in_curr_hunds += 3;
	if (ft_strcmp(nbr_str, "") == 0)
		return ;
	if ((ft_strcmp(nbr_str, "0") == 0 || ft_strcmp(nbr_str, "00") == 0
			||ft_strcmp(nbr_str, "000") == 0) && !flag)
		ft_print_key("0", 0, dict);
	ft_setup_curr_hund(nbr_str, &curr_hundreds);
	if (print_hundreds(curr_hundreds, dict, &flag))
		print_curr_th_pow(nbr_str, dict);
	ft_print_nbr(&(nbr_str[digits_in_curr_hunds]), dict, flag);
}
