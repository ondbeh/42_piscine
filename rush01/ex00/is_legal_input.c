/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_legal_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:20:51 by ksinn             #+#    #+#             */
/*   Updated: 2024/08/10 13:44:24 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_isvalid_box(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
}

int	ft_check_alternating(int *flag, char c)
{
	if (ft_isvalid_box(c))
	{
		if (*flag == 1)
			return (0);
		*flag = 1;
	}
	if (ft_isspace(c))
	{
		if (*flag == 0)
			return (0);
		*flag = 0;
	}
	return (1);
}

int	ft_is_legal_input(int argc, char *argv, int rules[16])
{
	int	i;
	int	nbr_args;
	int	flag;

	if (argc != 2)
		return (0);
	i = 0;
	nbr_args = 0;
	flag = 0;
	while (argv[i] && (ft_isspace(argv[i]) || ft_isvalid_box(argv[i])))
	{
		if (nbr_args >= 16)
			return (0);
		if (!ft_check_alternating(&flag, argv[i]))
			return (0);
		if (ft_isvalid_box(argv[i]))
		{
			rules[nbr_args] = argv[i] - '0';
			nbr_args++;
		}
		i++;
	}
	return (nbr_args == 16);
}
