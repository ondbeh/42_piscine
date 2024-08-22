/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:08:23 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/20 21:58:44 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				ret_value;
	unsigned int	i;

	i = 0;
	ret_value = 0;
	while (src[ret_value])
		ret_value++;
	while (i < size - 1 && src[i] && size)
	{
		dest[i] = src[i];
		++i;
	}
	if (size)
		dest[i] = '\0';
	return (ret_value);
}
