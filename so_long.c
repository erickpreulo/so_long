/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:31:00 by egomes            #+#    #+#             */
/*   Updated: 2021/09/30 13:33:27 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_enemi(t_vars *vars)
{
	if (vars->x == 1)
	{
		vars->enemi1.x = 0;
		vars->enemi1.y = 0;
		vars->enemi2.x = 0;
		vars->enemi2.y = 0;
	}
}

void	init(t_player *player, t_vars *vars)
{
	player->text.imag = mlx_xpm_file_to_image(vars->mlx,
			"xpm/mario_dir.xpm", &player->text.width, &player->text.height);
	player->text.imag_esq = mlx_xpm_file_to_image(vars->mlx,
			"xpm/mario_esq.xpm", &player->text.width, &player->text.height);
	vars->player2.text.imag = mlx_xpm_file_to_image(vars->mlx,
			"xpm/luigi_dir.xpm", &player->text.width, &player->text.height);
	vars->player2.text.imag_esq = mlx_xpm_file_to_image(vars->mlx,
			"xpm/luigi_esq.xpm", &player->text.width, &player->text.height);
	player->steps = 0;
	player->show_name = 0;
	vars->player2.show_name = 0;
	if (vars->player2.p != 1)
	{
		vars->player2.x = vars->maps.height;
		vars->player2.y = vars->maps.width;
	}
	init_enemi(vars);
}

int	exit_so_long(t_vars *vars)
{
	if (vars && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	printf("SEE YOU LATER\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars		vars;
	t_player	*player;

	player = &vars.player;
	if (ac != 2)
	{
		printf("Error\n");
		exit(0);
	}
	init_map(&vars, av[1]);
	vars.mlx = mlx_init();
	vars.last_update = 0;
	vars.win = mlx_new_window(vars.mlx,
			STEP * vars.maps.width, STEP * vars.maps.height, "SO_LONG");
	init(player, &vars);
	draw_game(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_so_long, &vars);
	mlx_loop(vars.mlx);
}

/*				for work, need comment others_caracteres function
int	main(int ac, char **av)
{
	t_vars		vars;
	t_player	*player;

	player = &vars.player;
	if (ac != 2)
	{
		printf("Error\n");
		exit(0);
	}
	init_map(&vars, av[1]);
	vars.mlx = mlx_init();
	vars.last_update = 0;
	vars.win = mlx_new_window(vars.mlx,
			STEP * vars.maps.width, STEP * vars.maps.height, "SO_LONG");
	init(player, &vars);
	draw_game(&vars);
	if (vars.x > 1)
		mlx_loop_hook(vars.mlx, enemi, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
*/