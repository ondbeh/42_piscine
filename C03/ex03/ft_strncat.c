/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:55:45 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/04 12:22:22 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ret_dest;

	ret_dest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && nb > 0)
	{
		*dest = *src;
		++dest;
		++src;
		--nb;
	}
	*dest = '\0';
	return (ret_dest);
}
