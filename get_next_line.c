/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:19:38 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/14 19:21:50 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int bytes_read;
	static const char *buf_copy[4096];
	char *temp;
	
	if (*line == NULL || fd < 0 || BUFFER_SIZE <= 0 ||
	 (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);

	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[bytes_read] = '\0';
			if (!buf_copy[fd])
				return(-1);
			while(!(newline_check(buf)))
				*buf_copy = ft_strjoin(buf_copy, buf);
		}
	*line = ft_substr(buf_copy, 0, strlen(buf_copy) - strlen(newline_check(buf)));
	return (0);
}
