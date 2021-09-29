/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:31:00 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 13:13:37 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_move(int *pos_player, int *pos_enemi, int increment, t_vars *vars)
{
	int i;
	int j;

	*pos_player += increment;
	if (vars->x == 1)
		*pos_enemi += increment;
	i = vars->player.y * vars->maps.width + vars->player.x;
	j = vars->player2.y * vars->maps.width + vars->player2.x;
	if ((vars->maps.buf[i] == 'E' || vars->maps.buf[j] == 'E') && vars->coins.count == 0)
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
	if (vars->maps.buf[i] == '1' || vars->maps.buf[i] == 'E'
		|| vars->maps.buf[j] == '1' || vars->maps.buf[j] == 'E')
    	*pos_player -= increment;
	else
        vars->player.steps++;
	i = vars->enemi.y * vars->maps.width + vars->enemi.x;
	if (vars->maps.buf[i] == '1' || vars->maps.buf[i] == 'E' || vars->maps.buf[i] == 'C')
    	*pos_enemi -= increment;
}

int	key_hook(int keycode, t_vars *vars)
{
	int i;
	int j;

	vars->savei = 0;
	vars->savej = 0;
	i = vars->player.y * vars->maps.width + vars->player.x;
	j = vars->player2.y * vars->maps.width + vars->player2.x;
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
	else if (keycode == DOWN)
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
	else if (keycode == LEFT)
	{
		vars->player.text.left = 1;
		if (vars->maps.buf[j] == 'S' || vars->maps.buf[j] == 's')
		{
			vars->savei = 1;
			make_move(&vars->player.x, &vars->enemi.x, - 1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player.x, &vars->enemi.x, - 1, vars);
	}
	else if (keycode == RIGHT)
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
	else if (keycode == UP2)
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
	else if (keycode == DOWN2)
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
	else if (keycode == LEFT2)
	{
		vars->player2.text.left = 1;
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
		{
			vars->savej = 1;
			make_move(&vars->player2.x, &vars->enemi.x, - 1, vars);
			draw_game(vars);
			return (0);
		}
		make_move(&vars->player2.x, &vars->enemi.x, - 1, vars);
	}
	else if (keycode == RIGHT2)
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
	else if (keycode == 45)
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
	else if (keycode == 35)
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
	else if (keycode == END)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("Steps = %d\nmissing coins = %d\nLOOSER!!!\n",
			vars->player.steps, vars->coins.count);
		free(vars->maps.buf);
		exit(0);
	}
	draw_game(vars);
	return (0);
}

void		init(t_player *player, t_vars *vars)
{
	player->text.imag = mlx_xpm_file_to_image(vars->mlx, "xpm/mario_dir.xpm", &player->text.width, &player->text.height);
	player->text.imag_esq = mlx_xpm_file_to_image(vars->mlx, "xpm/mario_esq.xpm", &player->text.width, &player->text.height);
	vars->player2.text.imag = mlx_xpm_file_to_image(vars->mlx, "xpm/luigi_dir.xpm", &player->text.width, &player->text.height);
	vars->player2.text.imag_esq = mlx_xpm_file_to_image(vars->mlx, "xpm/luigi_esq.xpm", &player->text.width, &player->text.height);
	player->steps = 0;
	player->show_name = 0;
	vars->player2.show_name = 0;
	if (vars->player2.p != 1)
	{
		vars->player2.x = vars->maps.height;
		vars->player2.y = vars->maps.width;
	}
}

int		main(int ac, char **av)
{
	t_vars	vars;
	t_player *player;

	player = &vars.player;
	int		*x;
	int		*y;
	if (ac != 2)
	{
		printf("Error\n");
		exit(0);
	}
	init_map(&vars, av[1]);
	vars.mlx = mlx_init();
	vars.last_update = 0;
	vars.win = mlx_new_window(vars.mlx, STEP * vars.maps.width, STEP * vars.maps.height, "SO_LONG");
	init(player, &vars);
	draw_game(&vars);
	if (vars.x > 1)
		mlx_loop_hook(vars.mlx, enemi, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
