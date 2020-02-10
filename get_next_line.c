/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:19:38 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/10 17:35:07 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	*buffer;

	line = NULL;
	buffer = 0;
	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if (!(fd = open("test.txt", O_RDONLY)))
		return (-1);
	if (!(ret = read(fd, buffer, BUFFER_SIZE)))
		return (-1);
	buffer[ret] = '\0';

	ft_putnbr_fd(ret, fd);
	ft_putstr_fd(buffer, fd);
	return (0);
}
