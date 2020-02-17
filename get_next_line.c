/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:19:38 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/17 13:49:32 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char	*buf;
	int bytes_read;
	static char *buf_copy;
	char *temp;
	char *found_newline;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0 ||
		(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	found_newline = 0;

	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (!buf_copy)
			buf_copy = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(buf_copy, buf);
			free(buf_copy);
			buf_copy = temp;
		}
		if (newline_check(buf, '\n'))
			break;
	}
	if (!bytes_read && !buf_copy)
		{
			*line = ft_strdup("");
			return(0);
		}
	if (bytes_read < 0)
			{
				if (buf_copy)
					free(buf_copy);
				return(-1);
			}	
	free(buf);

	if (newline_check(buf_copy, '\n'))
	{
		*line = ft_substr(buf_copy, 0, ft_strlen(buf_copy) - (ft_strlen(newline_check(buf_copy, '\n'))));
		temp = ft_strdup(newline_check(buf_copy, '\n') + 1);
		free(buf_copy);
		buf_copy = temp;
		return (1);
	}
	*line = ft_strdup(buf_copy);
	free(buf_copy);
	buf_copy = NULL;
	return (0);
}
