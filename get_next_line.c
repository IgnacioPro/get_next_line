/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:19:38 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/13 14:10:31 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	*buf;
	int bytes_read;
	static char *buf_copy;
	
	if (*line == NULL || fd < 0 ||
	 (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	while (ret = read(fd, buf, BUFFER_SIZE))
		
	buf[ret] = '\0';
	return (0);
}
