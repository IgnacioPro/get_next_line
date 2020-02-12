/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:24:52 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/12 16:06:15 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	long_n;

	if (n < 0)
	{
		write(fd, "-", 1);
		long_n = (unsigned int)(n * -1);
	}
	else
		long_n = (unsigned int)n;
	if (long_n >= 10)
		ft_putnbr_fd(long_n / 10, fd);
	ft_putchar_fd((char)(long_n % 10 + 48), fd);
}
