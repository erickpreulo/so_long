/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:30:16 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 18:08:01 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	end_hook(t_vars *vars, int keycode, int i, int j)
{
	if (keycode == END)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("Steps = %d\nmissing coins = %d\nLOOSER!!!\n",
			vars->player.steps, vars->coins.count);
		free(vars->maps.buf);
		exit(0);
	}
	if (keycode == 35)
	{
		vars->player2.show_name = !vars->player2.show_name;
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's'
			|| vars->maps.buf[j] == 'S' || vars->maps.buf[j] == 's')
		{
			if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
				vars->savei = 1;
			else
				vars->savej = 1;
			draw_game(vars);
			return (0);
		}
	}
	return (0);
}

int	others_hooks(t_vars *vars, int keycode, int i, int j)
{
	if (keycode == 45)
	{
		vars->player.show_name = !vars->player.show_name;
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's'
			|| vars->maps.buf[j] == 'S' || vars->maps.buf[j] == 's')
		{
			if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
				vars->savei = 1;
			else
				vars->savej = 1;
			draw_game(vars);
			return (0);
		}
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	i;
	int	j;

	vars->savei = 0;
	vars->savej = 0;
	i = vars->player.y * vars->maps.width + vars->player.x;
	j = vars->player2.y * vars->maps.width + vars->player2.x;
	player1(vars, keycode, j);
	player2(vars, keycode, i);
	others_hooks(vars, keycode, i, j);
	end_hook(vars, keycode, i, j);
	draw_game(vars);
	return (0);
}
