/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:26:53 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/14 13:37:45 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	int		pos;
	int		i;
	char	*temp;

	pos = ft_strchr(str, '\n');
	if (pos < 0)
		return (NULL);
	temp = (char *)malloc((pos + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i <= pos)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_last_line(char *str, char *buff, char **stat)
{
	int		pos;
	int		i;
	char	*temp;

	free(buff);
	if (!str)
		return (NULL);
	pos = ft_strlen(str);
	if (pos == 0)
	{
		free(*stat);
		*stat = NULL;
		return (NULL);
	}
	temp = (char *)malloc((pos + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < pos)
		temp[i] = str[i];
	temp[i] = '\0';
	free(*stat);
	*stat = NULL;
	return (temp);
}

int	readfile(int out, int fd, char **buff, char **stat)
{
	out = read(fd, *buff, BUFFER_SIZE);
	if (out < 0)
	{
		free(*buff);
		return (-1);
	}
	*stat = ft_strjoin(*stat, *buff, out);
	return (out);
}

char	*set_stat(char **stat, char *ret, char *buff)
{
	char	*temp;

	temp = ft_strdup(*stat + ft_strlen(ret));
	free(buff);
	free(*stat);
	*stat = temp;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*ret;
	static char	*stat[4096];
	int			out;

	out = 1;
	while (out > 0)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		if (ft_strchr(stat[fd], '\n') < 0)
		{
			out = readfile(out, fd, &buff, &stat[fd]);
			if (out == -1)
				return (NULL);
		}
		if (ft_strchr(stat[fd], '\n') < 0 && out < BUFFER_SIZE)
			return (get_last_line(stat[fd], buff, &stat[fd]));
		ret = get_line(stat[fd]);
		if (ret)
			return (set_stat(&stat[fd], ret, buff));
		free(buff);
	}
	return (NULL);
}

/* int	main()
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY); //"nxtlinesfabitest/files/panna.txt"
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	printf("\n");
	close(fd);
} */