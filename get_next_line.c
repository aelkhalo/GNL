/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:17:58 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/01/04 18:05:57 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_bsn(char *buff)
{
	int i;

	i = -1;
	if (!buff)
		return (0);
	while (buff[++i] != '\0')
		if (buff[i] == '\n')
		{
			return (1);
			break ;
		}
	return (0);
}
char ft_fill(char *tmp)
{
	char *line;
	int i;
	
}

char	*getline1(char **buff)
{
	char	*line;
	int		i;
	char	*tmp;

	i = 0;
	tmp = *buff;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			break ;
		i++;
	}
	if (!(line = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			break ;
		else
			line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	*buff = ft_substr1(tmp, i + 1);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	int			sz;
	static char	*buff;
	char		*c;
	int			check;

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	while (!(check = is_bsn(buff)))
	{
		if (!(c = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (NULL);
		sz = read(fd, c, BUFFER_SIZE);
		c[sz] = '\0';
		buff = ft_strjoin(buff, c);
		free(c);
		if (sz == 0)
			break ;
	}
	*line = getline1(&buff);
	if (!check)
	{
		free(buff);
		buff = NULL;
	}
	return (check ? 1 : 0);
}
