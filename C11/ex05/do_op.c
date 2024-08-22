/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:07:56 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/13 14:49:17 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);

int	ft_zero(int a, int b)
{
	return (0 * a * b);
}

int	get_op_nbr(char *str)
{
	char	op;

	op = *str;
	++str;
	if (*str)
		return (0);
	else if (op == '+')
		return (1);
	else if (op == '-')
		return (2);
	else if (op == '*')
		return (3);
	else if (op == '/')
		return (4);
	else if (op == '%')
		return (5);
	else
		return (0);
}

void	print_result(int (*f[6])(int, int), int op_nbr, int value1, int value2)
{
	int	result;

	if (!value2 && op_nbr == 4)
	{
		write (1, "Stop : division by zero\n", 24);
		return ;
	}
	if (!value2 && op_nbr == 5)
	{
		write (1, "Stop : modulo by zero\n", 22);
		return ;
	}
	result = (*(f[op_nbr]))(value1, value2);
	ft_putnbr(result);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	value1;
	int	value2;
	int	op_nbr;
	int	(*f[6])(int, int);

	f[0] = &ft_zero;
	f[1] = &ft_add;
	f[2] = &ft_sub;
	f[3] = &ft_mul;
	f[4] = &ft_div;
	f[5] = &ft_mod;
	if (argc != 4)
		return (1);
	op_nbr = get_op_nbr(argv[2]);
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	print_result(f, op_nbr, value1, value2);
	return (0);
}
