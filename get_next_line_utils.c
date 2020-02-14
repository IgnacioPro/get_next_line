/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:24:52 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/14 17:57:30 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*string;
	int		src_size;
	int		i;

	i = 0;
	src_size = 0;
	while (src[src_size])
	{
		src_size++;
	}
	string = (char *)malloc(src_size * sizeof(*src) + 1);
	if (!string)
		return (NULL);
	while (i < src_size)
	{
		string[i] = src[i];
		i++;
	}
	string[src_size] = '\0';
	return (string);
	free(string);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*newline_check(const char *s)
{
	char	*str;

	str = (char *)s;
	while (*str != '\n')
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}