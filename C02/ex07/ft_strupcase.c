/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:22:26 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/03 19:27:45 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*ret_str;

	ret_str = str;
	while (*str != '\0')
	{
		if (*str >= 97 && *str <= 122)
			*str = *str - 32;
		++str;
	}
	return (ret_str);
}
