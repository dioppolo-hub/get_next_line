/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:26:35 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/14 13:29:56 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <bsd/string.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char *s1, char *s2, int out);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*get_line(char *str);
char	*get_last_line(char *str, char *buff, char **stat);
char	*set_stat(char **stat, char *ret, char *buff);
int		readfile(int out, int fd, char **buff, char **stat);

#endif