/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:38:56 by aelkhalo          #+#    #+#             */
/*   Updated: 2019/12/27 17:43:34 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
char		*ft_substr1(char *s, unsigned int start);
#endif
