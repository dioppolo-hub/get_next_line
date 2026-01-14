/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:25:09 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/14 11:00:12 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*get_line(char *str);
char	*get_last_line(char *str);
int		read_and_join(int fd, char **stat);

#endif