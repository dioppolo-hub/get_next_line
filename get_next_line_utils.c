/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:24:39 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/09 12:33:51 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (!s[i] && c == '\0')
		return (i);
	return (-2);
}

static char	*scorri_s(char *s1, char *s2,
	char *newstr, size_t lens1)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[i - lens1])
	{
		newstr[i] = s2[i - lens1];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		lens1;
	size_t		lens2;
	size_t		tot;
	size_t		i;
	char		*newstr;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	tot = lens1 + lens2;
	i = 0;
	newstr = malloc((tot + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	return (scorri_s(s1, s2, newstr, lens1));
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
