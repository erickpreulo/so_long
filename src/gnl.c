/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:39:49 by egomes            #+#    #+#             */
/*   Updated: 2021/09/30 00:56:45 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	null_buffer(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (i < 100000)
		buffer[i++] = '\0';
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		r;
	char	*buffer;
	char	c;

	buffer = (char *)malloc(100000);
	null_buffer(buffer);
	i = 0;
	c = '0';
	r = 1;
	while (r != 0 && c != '\n' && c != '\0')
	{
		r = read(fd, &c, 1);
		if (c == '\n' || c == '\0' || r == 0)
			break ;
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
	}
	*line = buffer;
	return (r);
}
