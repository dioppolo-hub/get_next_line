/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:21:08 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/08 13:01:27 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	//size_t	count;
	char	*buff;
	//char 	*str;
	int		i;
	size_t		out;

	out = 1;
	i = 0;
	while(out > 0)
	{
		buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
		//str = (char *)malloc(sizeof(buff));
		//printf("%zu\n", out);
		out = read(fd, buff, BUFFER_SIZE);
		//str = buff;
		while (buff[i])
		{
			if(buff[i] == '\n')
			{
				printf("ciao\n");
				return (buff);
			}
			i++;
		}

		//free (str);
	}
	return (buff);
} 

int	main()
{
	int fd;
	int	i = 0;

	fd = open("test.txt", O_RDONLY);
	while (i < 30)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}

	close(fd);
}