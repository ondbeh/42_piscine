/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:14:12 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/19 21:00:36 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_link
{
	char			hex[16];
	int				pos;
	struct s_link	*next;
}			t_link;

void	ft_putstr(const char *str);
void	ft_putstr_error(const char *str);
int		print_error(char *file_name, int v_errno);
int		ft_str_is_printable(char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
t_link	*ft_new_link(int pos);

#endif