/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:10:33 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/03 20:12:42 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*ret_str;

	ret_str = str;
	while (*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
			*str = *str + 32;
		++str;
	}
	return (ret_str);
}
