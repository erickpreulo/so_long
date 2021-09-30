/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:33:16 by egomes            #+#    #+#             */
/*   Updated: 2021/09/30 02:40:08 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	make_cont(t_vars *vars, int j)
{
	if (vars->maps.buf[j] == 'S' && vars->savei == 0)
	{
		vars->player2.y = vars->portal.y1;
		vars->player2.x = vars->portal.x1;
	}
	else if (vars->maps.buf[j] == 's' && vars->savei == 0)
	{
		vars->player2.y = vars->portal.y;
		vars->player2.x = vars->portal.x;
	}
}

void	make_move_portal(t_vars *vars, int i, int j)
{
	if ((vars->maps.buf[i] == 'E' || vars->maps.buf[j] == 'E')
		&& vars->coins.count == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("CONGRATULATIONS!!!\nSteps = %d\n", vars->player.steps);
		free(vars->maps.buf);
		exit(0);
	}
	if (vars->maps.buf[i] == 'S' && vars->savej == 0)
	{
		vars->player.y = vars->portal.y1;
		vars->player.x = vars->portal.x1;
	}
	else if (vars->maps.buf[i] == 's' && vars->savej == 0)
	{
		vars->player.y = vars->portal.y;
		vars->player.x = vars->portal.x;
	}
	make_cont(vars, j);
}

void	make_move(int *pos_player, int *pos_enemi, int increment, t_vars *vars)
{
	int	i;
	int	j;

	*pos_player += increment;
	if (vars->x == 1)
		*pos_enemi += increment;
	i = vars->player.y * vars->maps.width + vars->player.x;
	j = vars->player2.y * vars->maps.width + vars->player2.x;
	make_move_portal(vars, i, j);
	if (vars->maps.buf[i] == '1' || vars->maps.buf[j] == '1')
		*pos_player -= increment;
	else
		vars->player.steps++;
	i = vars->enemi.y * vars->maps.width + vars->enemi.x;
	if (vars->maps.buf[i] == '1' || vars->maps.buf[i] == 'E'
		|| vars->maps.buf[i] == 'C')
		*pos_enemi -= increment;
}
