/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:45:49 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 17:51:06 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_first_line(t_vars *vars, char *line)
{
	int	i;

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

void	find_in_map(t_vars *vars)
{
	if (vars->maps.buf[vars->maps.i] == 'C')
		vars->maps.c = 1;
	else if (vars->maps.buf[vars->maps.i] == 'P')
		vars->maps.p += 1;
	else if (vars->maps.buf[vars->maps.i] == 'p')
		vars->maps.p2 += 1;
	else if (vars->maps.buf[vars->maps.i] == 'E')
		vars->maps.e = 1;
	else if (vars->maps.buf[vars->maps.i] == 'S')
		vars->maps.s += 1;
	else if (vars->maps.buf[vars->maps.i] == 's')
		vars->maps.s2 += 1;
	else if (vars->maps.buf[vars->maps.i] == '2')
		vars->maps.x2 += 1;
	else if (vars->maps.buf[vars->maps.i] == '3')
		vars->maps.x3 += 1;
	else if (vars->maps.buf[vars->maps.i] == '4')
		vars->maps.x4 += 1;
}

void	validade_all_map(t_vars *vars, char *line)
{
	vars->maps.x2 = 0;
	vars->maps.x3 = 0;
	vars->maps.x4 = 0;
	vars->maps.s = 0;
	vars->maps.s2 = 0;
	vars->maps.p = 0;
	vars->maps.p2 = 0;
	vars->maps.e = 0;
	vars->maps.c = 0;
	vars->maps.i = 0;
	while (vars->maps.i < vars->maps.width * vars->maps.height)
	{
		find_in_map(vars);
		vars->maps.i++;
	}
	if (vars->maps.c == 0 || vars->maps.p != 1 || vars->maps.p2 > 1
		|| vars->maps.s > 1 || vars->maps.s2 > 1 || vars->maps.e == 0
		|| vars->maps.x2 > 1 || vars->maps.x3 > 1 || vars->maps.x4 > 1)
	{
		printf("Error\nMap invalid");
		free(line);
		free(vars->maps.buf);
		exit(0);
	}
}
