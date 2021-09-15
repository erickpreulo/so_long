/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:31:00 by egomes            #+#    #+#             */
/*   Updated: 2021/09/14 20:35:49 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
}

int	main(void)
{
	int i;
	int j;
	t_vars	vars;

	i = 1920;
	j = 1080;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
