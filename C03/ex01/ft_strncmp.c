/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:11:52 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/04 09:40:14 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	ret_value;

	ret_value = 0;
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		ret_value = *s1 - *s2;
		if (ret_value != 0)
			return (ret_value);
		++s1;
		++s2;
		--n;
	}
	if ((*s1 == '\0' || *s2 == '\0') && n > 0)
		ret_value = *s1 - *s2;
	return (ret_value);
}
