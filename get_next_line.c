/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:19:38 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/12 16:06:12 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	*buf[BUFFER_SIZE];
	
	while(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE) && fd != -1)
	{
		
	}
	buf[ret] = '\0';
	return (0);
}

	
//	while (ret = read(fd, buf, BUFFER_SIZE))