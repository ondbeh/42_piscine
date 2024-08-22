/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:54 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/06 10:48:53 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*temp_to_find;
	char	*curr_ret;

	curr_ret = str;
	temp_to_find = to_find;
	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		while (*temp_to_find == *curr_ret && *temp_to_find != '\0')
		{
			++temp_to_find;
			++curr_ret;
		}
		if (*temp_to_find == '\0')
			return (str);
		++str;
		temp_to_find = to_find;
		curr_ret = str;
	}
	return ((void *)0);
}
