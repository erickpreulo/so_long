/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:33:59 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 14:25:50 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	validate_first_line(t_vars *vars, char *line)
{
	int i;

	i = 0;
	while (i < vars->maps.width)
	{
		if (line[i] != '1')
		{
			printf("Error\nMap invalid");
			free(line);
			free(vars->maps.buf);
			exit(0);
		}
		i++;
	}
}

void	validade_line(t_vars *vars, char *line)
{
	if (line[0] != '1' || line[vars->maps.width - 1] != '1')
	{
		printf("Error\nMap invalid");
		free(line);
		free(vars->maps.buf);
		exit(0);
	}
}

void	validade_all_map(t_vars *vars, char *line)
{
	int i;
	int c;
	int e;
	int P;
	int p;
	int S;
	int s;
	int x2;
	int x3;
	int x4;

	x2 = 0;
	x3 = 0;
	x4 = 0;
	S = 0;
	s = 0;
	P = 0;
	p = 0;
	e = 0;
	c = 0;
	i = 0;
	while (i < vars->maps.width * vars->maps.height)
	{
		if (vars->maps.buf[i] == 'C')
			c = 1;
		else if (vars->maps.buf[i] == 'P')
			P += 1;
		else if (vars->maps.buf[i] == 'p')
			p += 1;
		else if (vars->maps.buf[i] == 'E')
			e = 1;
		else if (vars->maps.buf[i] == 'S')
			S += 1;
		else if (vars->maps.buf[i] == 's')
			s += 1;
		else if (vars->maps.buf[i] == '2')
			x2 += 1;
		else if (vars->maps.buf[i] == '3')
			x3 += 1;
		else if (vars->maps.buf[i] == '4')
			x4 += 1;
		i++;
	}
	if (c == 0 || P != 1 || p > 1 || S > 1 || s > 1 || e == 0 || x2 > 1
		|| x3 > 1 || x4 > 1)
	{
		printf("Error\nMap invalid");
		free(line);
		free(vars->maps.buf);
		exit(0);
	}
}

void	init_map(t_vars *vars, char *map)
{
	int fd;
	int ret;
	char *line;
	int i;

	vars->maps.buf = malloc(sizeof(char) * 10000);
	fd = open(map, O_RDONLY);
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
			i++;
		}
		vars->maps.height++;
	}
	validade_all_map(vars, line);
	free(line);
}

