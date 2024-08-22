/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:19:41 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/06 10:37:54 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;

	counter = 0;
	while (counter < size - 1 && *dest != '\0')
	{
		++dest;
		++counter;
	}
	while (counter < size - 1 && *src != '\0')
	{
		*dest = *src;
		++src;
		++dest;
		++counter;
	}
	dest[counter] = '\0';
	return (counter);
}
