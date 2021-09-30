/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:33:59 by egomes            #+#    #+#             */
/*   Updated: 2021/09/30 01:06:09 by egomes           ###   ########.fr       */
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

void	size(t_vars *vars, int i)
{
	if (vars->maps.line[i] == 'P')
	{
		vars->player.x = i;
		vars->player.y = vars->maps.height;
	}
	if (vars->maps.line[i] == 's')
	{
		vars->portal.x1 = i;
		vars->portal.y1 = vars->maps.height;
	}
	if (vars->maps.line[i] == 'S')
	{
		vars->portal.x = i;
		vars->portal.y = vars->maps.height;
	}
	if (vars->maps.line[i] == 'p')
	{
		vars->player2.p = 1;
		vars->player2.x = i;
		vars->player2.y = vars->maps.height;
	}
	size_cont(vars, i, vars->maps.line);
}

void	read_file(t_vars *vars, int ret, int fd)
{
	int	i;

	ret = get_next_line(fd, &vars->maps.line);
	vars->maps.width = ft_strlen(vars->maps.line);
	validate_first_line(vars, ret);
	ft_strcat(vars->maps.buf, vars->maps.line);
	vars->maps.height = 1;
	vars->coins.count = 0;
	vars->x = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &vars->maps.line);
		if (ret == 0)
			validate_first_line(vars, ret);
		validate_line(vars);
		ft_strcat(vars->maps.buf, vars->maps.line);
		i = 0;
		while (vars->maps.line[i] != '\0')
		{
			size(vars, i);
			i++;
		}
		vars->maps.height++;
	}
}

void	init_map(t_vars *vars, char *map)
{
	int		fd;
	int		ret;
	int		i;

	vars->maps.buf = malloc(sizeof(char) * 10000);
	i = 0;
	while (i < 10000)
		vars->maps.buf[i++] = '\0';
	ret = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nfile cannot be read");
		free(vars->maps.buf);
		exit(0);
	}
	read_file(vars, ret, fd);
	validade_all_map(vars);
	free(vars->maps.line);
}
