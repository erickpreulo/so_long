/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:33:59 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 17:50:33 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	size_cont(t_vars *vars, int i, char *line)
{
	if (line[i] == 'C')
		vars->coins.count++;
	if (line[i] == '2')
	{
		vars->x += 1;
		vars->enemi.x = i;
		vars->enemi.y = vars->maps.height;
	}
	if (line[i] == '3')
	{
		vars->x += 1;
		vars->enemi1.x = i;
		vars->enemi1.y = vars->maps.height;
	}
	if (line[i] == '4')
	{
		vars->x += 1;
		vars->enemi2.x = i;
		vars->enemi2.y = vars->maps.height;
	}
}

void	size(t_vars *vars, int i, char *line)
{
	if (line[i] == 'P')
	{
		vars->player.x = i;
		vars->player.y = vars->maps.height;
	}
	if (line[i] == 's')
	{
		vars->portal.x1 = i;
		vars->portal.y1 = vars->maps.height;
	}
	if (line[i] == 'S')
	{
		vars->portal.x = i;
		vars->portal.y = vars->maps.height;
	}
	if (line[i] == 'p')
	{
		vars->player2.p = 1;
		vars->player2.x = i;
		vars->player2.y = vars->maps.height;
	}
	size_cont(vars, i, line);
}

void	read_file(t_vars *vars, char *line, int ret, int fd)
{
	if (fd == -1)
	{
		printf("Error\nfile cannot be read");
		free(vars->maps.buf);
		exit(0);
	}
	ret = get_next_line(fd, &line);
	vars->maps.width = ft_strlen(line);
	validate_first_line(vars, line);
	ft_strcat(vars->maps.buf, line);
	vars->maps.height = 1;
	vars->coins.count = 0;
	vars->x = 0;
}

void	init_map(t_vars *vars, char *map)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	vars->maps.buf = malloc(sizeof(char) * 10000);
	fd = open(map, O_RDONLY);
	read_file(vars, line, ret, fd);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0)
			validate_first_line(vars, line);
		validade_line(vars, line);
		ft_strcat(vars->maps.buf, line);
		i = 0;
		while (line[i] != '\0')
		{
			size(vars, i, line);
			i++;
		}
		vars->maps.height++;
	}
	validade_all_map(vars, line);
	free(line);
}
