/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:21:08 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/09 12:45:49 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		pos;
	int		i;
	char	*temp;

	pos = ft_strchr(str, '\n');
	if(pos < 0)
		return (NULL);
	temp = (char *)malloc((pos + 1) * sizeof(char));
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

char	*get_last_line(char *str)
{
	int		pos;
	int		i;
	char	*temp;

	pos = ft_strchr(str, '\0');
	if(pos < 0)
		return (NULL);
//	printf("\nultima lettura: %s\n", str);
	temp = (char *)malloc((pos) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < pos)
	{
		temp[i] = str[i];
		i++;
	}
	return(temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*ret;
	static char	*stat;
	int			out;

	out = 1;
	if(!stat)
		stat = (char *)malloc(0);
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
			return (ret = get_last_line(stat));
		}
		ret = get_line(stat);
		if (ret)
		{
			stat += ft_strlen(ret);
			free(buff);
			return (ret);
		}
		free(buff);
	}
	return (stat);
} 
/* 
int	main()
{
	int fd;
	int	i = 0;
	char *str;

	fd = open("test.txt", O_RDONLY);
	while (i < 18)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		i++;
	}
	printf("\n");

	close(fd);
} */