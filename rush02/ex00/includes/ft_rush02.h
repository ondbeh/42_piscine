/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:29:24 by obehavka          #+#    #+#             */
/*   Updated: 2024/08/17 23:39:32 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define DEF_DICT "dicts/numbers.dict"
# define BUF_SIZE 5000
# define MAX_NUM_SIZE 42

typedef struct s_dict_record
{
	char	*key;
	char	*name;
}			t_dict_record;

t_dict_record	*ft_build_dict(char **split_file);
t_dict_record	*ft_kill_dictionary(t_dict_record *dictionary);
char			*ft_get_file_str(char *filename);
char			*ft_return_zero(void);
char			**ft_split(char *str, char *charset);
char			**ft_kill_split_string(char **split_string);
void			ft_print_nbr(char *nbr_str, t_dict_record *dict, int flag);
void			ft_print_key(char *key, int space_flag, t_dict_record *dict);
void			ft_print_digit(char c, int space_flag, t_dict_record *dict);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(const char *str);

#endif