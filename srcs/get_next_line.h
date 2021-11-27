/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2021/11/27 03:21:50 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // REMOVE!!

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *str, int c);

typedef struct s_files
{
	int				fd;
	char			*data;
	struct s_files	*next;
}					t_files;

#endif