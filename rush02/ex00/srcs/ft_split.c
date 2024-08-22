/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:19:27 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/17 15:30:04 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_isseparator(char c, char *sepstr)
{
	while (*sepstr)
	{
		if (*sepstr == c)
			return (1);
		++sepstr;
	}
	return (0);
}

int	ft_countstrings(char *str, char *sepstr)
{
	int	flag;
	int	word_count;

	flag = 1;
	word_count = 0;
	while (*str)
	{
		if (!ft_isseparator(*str, sepstr))
		{
			if (flag)
			{
				flag = 0;
				++word_count;
			}
		}
		else
			flag = 1;
		++str;
	}
	return (word_count);
}

char	*ft_get_word(char **str, char *charset)
{
	int		strlen;
	char	*ret_ptr;
	char	*tmp_ptr;

	tmp_ptr = *str;
	strlen = 0;
	while (*tmp_ptr && !ft_isseparator(*tmp_ptr, charset))
	{
		++strlen;
		++tmp_ptr;
	}
	ret_ptr = malloc((strlen + 1) * sizeof(char));
	if (!ret_ptr)
		return (NULL);
	tmp_ptr = ret_ptr;
	while (**str && !ft_isseparator(**str, charset))
	{
		*tmp_ptr = **str;
		++tmp_ptr;
		++(*str);
	}
	*tmp_ptr = '\0';
	return (ret_ptr);
}

char	**ft_kill_split_string(char **split_string)
{
	char	**tmp_ptr;

	if (split_string == NULL)
		return (NULL);
	tmp_ptr = split_string;
	while (*tmp_ptr)
	{
		free (*tmp_ptr);
		tmp_ptr++;
	}
	free (split_string);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret_ptr;
	char	**tmp_ptr;

	if (!str)
		return (NULL);
	ret_ptr = malloc ((ft_countstrings (str, charset) + 1) * sizeof(char *));
	if (!ret_ptr)
		return (NULL);
	tmp_ptr = ret_ptr;
	while (*str)
	{
		if (!ft_isseparator(*str, charset))
		{
			*tmp_ptr = ft_get_word(&str, charset);
			if (!(*tmp_ptr))
				return (ft_kill_split_string(ret_ptr));
			++tmp_ptr;
		}
		else
			++str;
	}
	*tmp_ptr = NULL;
	return (ret_ptr);
}
