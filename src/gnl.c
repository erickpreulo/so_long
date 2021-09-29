/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:39:49 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 12:18:52 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		get_next_line(int fd, char **line)
{
	int i;
	int r;
	char *buffer;
	char c;

	if (!(buffer = (char *)malloc(100000)))
		return (-1);
	i = 0;
    while (i < 100000)
        buffer[i++] = '\0';
    i = 0;
	while ((r = read(fd, &c, 1)) && c != '\n' && c != '\0')
	{
        if (c == '\n' || c == '\0')
            break;
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}
