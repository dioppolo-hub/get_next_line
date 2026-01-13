/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:21:08 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/13 13:45:50 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *str)
{
	int		pos;
	int		i;
	char	*temp;

	pos = ft_strchr(str, '\n');
	if(pos < 0)
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
	return(temp);
}

static char	*get_last_line(char *str)
{
	int		pos;
	int		i;
	char	*temp;

	if (!str)
		return (NULL);
	pos = ft_strlen(str);
	if (pos == 0)
		return (NULL);
	temp = (char *)malloc((pos + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < pos)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	//free(str);
	return (temp);
}

/* char *line(char *stat, char *buff, char *ret, int out)
{
	char	*temp;

	if (ft_strchr(stat, '\n') < 0 && out < BUFFER_SIZE)
		{
			free(buff);
			ret = get_last_line(stat);
			free(stat);
			stat = NULL;
			return (ret);
		}
		ret = get_line(stat);
		if (ret)
		{
			temp = ft_strdup(stat + ft_strlen(ret));
			free(buff);
			free(stat);
			stat = temp;
			return (ret);
		}

} */

char	*get_next_line(int fd)
{
	char		*buff;
	char		*ret;
	static char	*stat = NULL;
	int			out;
	char		*temp;

	out = 1;
	while(out > 0)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		if (ft_strchr(stat, '\n') < 0)
		{
			out = read(fd, buff, BUFFER_SIZE);
			if (out < 0)
			{
				free(buff);
				return (NULL);
			}
			buff[out] = '\0';
			stat = ft_strjoin(stat, buff);
		}
		if (ft_strchr(stat, '\n') < 0 && out < BUFFER_SIZE)
		{
			free(buff);
			ret = get_last_line(stat);
			free(stat);
			stat = NULL;
			return (ret);
		}
		ret = get_line(stat);
		if (ret)
		{
			temp = ft_strdup(stat + ft_strlen(ret));
			free(buff);
			free(stat);
			stat = temp;
			return (ret);
		}
		free(buff);
	}
	return (NULL);
} 

int	main()
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
}