/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:32:48 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/20 21:04:25 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char	*str)
{
	char	*ret_ptr;
	int		flag;

	ret_ptr = str;
	flag = 1;
	while (*str)
	{
		if (!ft_is_alpha(*str))
			flag = 1;
		else if (flag && *str >= 'a' && *str <= 'z')
		{
			flag = 0;
			*str -= 32;
		}
		else if (flag)
			flag = 0;
		else if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		++str;
	}
	return (ret_ptr);
}
