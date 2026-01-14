/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:26:46 by dioppolo          #+#    #+#             */
/*   Updated: 2026/01/14 13:30:09 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	free(s1);
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2, int out)
{
	size_t		lens1;
	size_t		lens2;
	size_t		tot;
	size_t		i;
	char		*newstr;

	s2[out] = '\0';
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
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

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	size_t	nmemb;
	char	*dup;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	nmemb = ft_strlen(s);
	dup = (char *)malloc((nmemb + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
