/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_player_movs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:07:35 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 18:08:34 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player1_lef_rig(t_vars *vars, int keycode, int j)
{
	if (keycode == LEFT)
	{
		vars->player.text.left = 1;
		if (vars->maps.buf[j] == 'S' || vars->maps.buf[j] == 's')
		{
			vars->savei = 1;
			make_move(&vars->player.x, &vars->enemi.x, -1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player.x, &vars->enemi.x, -1, vars);
	}
	if (keycode == RIGHT)
	{
		if (vars->maps.buf[j] == 'S' || vars->maps.buf[j] == 's')
		{
			vars->savei = 1;
			make_move(&vars->player.x, &vars->enemi.x, 1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player.x, &vars->enemi.x, 1, vars);
	}
	return (0);
}

int	player1(t_vars *vars, int keycode, int j)
{
	if (keycode == UP)
	{
		if (vars->maps.buf[j] == 'S' || vars->maps.buf[j] == 's')
		{
			vars->savei = 1;
			make_move(&vars->player.y, &vars->enemi.y, -1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player.y, &vars->enemi.y, -1, vars);
	}
	if (keycode == DOWN)
	{
		if (vars->maps.buf[j] == 'S' || vars->maps.buf[j] == 's')
		{
			vars->savei = 1;
			make_move(&vars->player.y, &vars->enemi.y, 1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player.y, &vars->enemi.y, 1, vars);
	}
	player1_lef_rig(vars, keycode, j);
	return (0);
}

int	player2_lef_rig(t_vars *vars, int keycode, int i)
{
	if (keycode == LEFT2)
	{
		vars->player2.text.left = 1;
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
		{
			vars->savej = 1;
			make_move(&vars->player2.x, &vars->enemi.x, -1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player2.x, &vars->enemi.x, -1, vars);
	}
	if (keycode == RIGHT2)
	{
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
		{
			vars->savej = 1;
			make_move(&vars->player2.x, &vars->enemi.x, 1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player2.x, &vars->enemi.x, 1, vars);
	}
	return (0);
}

int	player2(t_vars *vars, int keycode, int i)
{
	if (keycode == UP2)
	{
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
		{
			vars->savej = 1;
			make_move(&vars->player2.y, &vars->enemi.y, -1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player2.y, &vars->enemi.y, -1, vars);
	}
	if (keycode == DOWN2)
	{
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
		{
			vars->savej = 1;
			make_move(&vars->player2.y, &vars->enemi.y, 1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player2.y, &vars->enemi.y, 1, vars);
	}
	player2_lef_rig(vars, keycode, i);
	return (0);
}
