/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:26:43 by aelkhalo          #+#    #+#             */
/*   Updated: 2019/12/27 17:44:06 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = ft_strlen((char *)s1);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s12;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return (strdup(s2));
	i = -1;
	j = -1;
	len = strlen((char *)s1) + strlen((char *)s2);
	s12 = malloc(sizeof(char) * len + 1);
	if (!s12)
		return (NULL);
	while (s1[++i] != '\0')
		s12[i] = s1[i];
	while (s2[++j] != '\0')
		s12[i++] = s2[j];
	s12[i] = '\0';
	free(s1);
	return ((char *)s12);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	if (s)
	{
		s1 = (char *)malloc(len + 1 * sizeof(char));
		if (!s1 || (size_t)start >= strlen((char*)s))
			return (strdup("\0"));
		while (s[i] && len > 0)
		{
			s1[j] = s[i];
			j++;
			i++;
			len--;
		}
		s1[j] = '\0';
		return ((char *)s1);
	}
	return (NULL);
}

char	*ft_substr1(char *s, unsigned int start)
{
	char	*red;
	int		i;
	int		r;

	r = 0;
	i = 0;
	if (!s)
		return (0);
	if (start > strlen(s))
		r = 0;
	r = strlen(s);
	red = (char *)malloc(sizeof(char) * (r + 1));
	if (!red)
		return (0);
	while (s[start] && i < r)
	{
		red[i++] = s[start++];
	}
	red[i] = '\0';
	free(s);
	return (red);
}
