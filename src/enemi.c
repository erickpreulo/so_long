/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:40:16 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 16:51:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
void		free_way_enemi(t_vars *vars)
{
	int i;

	int random1 = (rand() % 3) - 1;
	int random2 = (rand() % 3) - 1;
	if (random2 < 0)
		vars->enemi.p = 1;
	vars->enemi.x += random1;
	vars->enemi.y += random2;
	i = vars->enemi.y * vars->maps.width + vars->enemi.x;
	if (vars->maps.buf[i] != '0' && vars->maps.buf[i] != 'P')
	{
		vars->enemi.x -= random1;
		vars->enemi.y -= random2;
		free_way_enemi(vars);
	}
}

void		free_way_enemi1(t_vars *vars)
{
	int i;

	int random1 = (rand() % 3) - 1;
	int random2 = (rand() % 3) - 1;
	if (random2 < 0)
		vars->enemi1.p = 1;
	vars->enemi1.x += random1;
	vars->enemi1.y += random2;
	i = vars->enemi1.y * vars->maps.width + vars->enemi1.x;
	if (vars->maps.buf[i] != '0' && vars->maps.buf[i] != 'P')
	{
		vars->enemi1.x -= random1;
		vars->enemi1.y -= random2;
		free_way_enemi1(vars);
	}
}

void		free_way_enemi2(t_vars *vars)
{
	int i;

	int random1 = (rand() % 3) - 1;
	int random2 = (rand() % 3) - 1;
	if (random2 < 0)
		vars->enemi2.p = 1;
	vars->enemi2.x += random1;
	vars->enemi2.y += random2;
	i = vars->enemi2.y * vars->maps.width + vars->enemi2.x;
	if (vars->maps.buf[i] != '0' && vars->maps.buf[i] != 'P')
	{
		vars->enemi2.x -= random1;
		vars->enemi2.y -= random2;
		free_way_enemi2(vars);
	}
}

int	enemi(t_vars *vars)
{
	struct timespec t;
	int i;

	clock_gettime(CLOCK_REALTIME, &t);
	int64_t now = t.tv_sec;

	if (now <= vars->last_update)
		return (0);
	vars->last_update = now;
	free_way_enemi(vars);
	free_way_enemi1(vars);
	free_way_enemi2(vars);
	draw_game(vars);
	return(0);
}
*/