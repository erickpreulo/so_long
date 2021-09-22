/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:31:00 by egomes            #+#    #+#             */
/*   Updated: 2021/09/19 23:26:18 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_texture
{
	void*	imag;
	int		width;
	int		height;
}				t_texture;


typedef struct s_player
{
	t_texture text;
	int		x;
	int		y;
	int		steps;
	int		show_name;
}				t_player;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		i;
	int		j;
	t_player	player;
}				t_vars;

void		draw_game(t_vars *vars)
{
	t_texture	wall;
	t_texture gras;
	t_player *player;
	char	*steps;

	int i;
	int j;
	player = &vars->player;
	wall.imag = mlx_xpm_file_to_image(vars->mlx, "texter.xpm", &wall.width, &wall.height);
	gras.imag = mlx_xpm_file_to_image(vars->mlx, "gras.xpm", &gras.width, &gras.height);
	i = 0;
	while(i < LARGURA)
	{
		j = 0;
		while (j < ALTURA)
		{
			if (i == 0 || j == 0 || i == LARGURA - 1 || j == ALTURA - 1)
				mlx_put_image_to_window(vars->mlx, vars->win, wall.imag, i * STEP, j * STEP);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, gras.imag, i * STEP, j * STEP);
			if (i == player->x && j == player->y)
				mlx_put_image_to_window(vars->mlx, vars->win, player->text.imag, i * STEP, j * STEP);
			j++;
		}
		i++;
	}
	if (player->show_name)
		mlx_string_put(vars->mlx, vars->win, player->x * STEP + 10, player->y * STEP - 15, 0xff0000, "erick");
	steps = ft_itoa(player->steps);
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0xff0000, steps);
	free(steps);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_move(int *pos, int increment, int *steps)
{
	*pos += increment;
	(*steps)++;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == UP && vars->player.y > 1)
		make_move(&vars->player.y, -1, &vars->player.steps);
	// {
	// 	vars->player.steps++;
	// 	printf("UP\n");
	// 	vars->player.y--;
	// }
	else if (keycode == DOWN && vars->player.y < ALTURA - 2)
		make_move(&vars->player.y, 1, &vars->player.steps);
	else if (keycode == LEFT && vars->player.x > 1)
		make_move(&vars->player.x, -1, &vars->player.steps);
	else if (keycode == RIGHT && vars->player.x < LARGURA - 2)
		make_move(&vars->player.x, 1, &vars->player.steps);
	else if (keycode == 45)
		vars->player.show_name = !vars->player.show_name;
	draw_game(vars);
	return (0);
}

void		init_player(t_player *player, t_vars *vars)
{
	player->text.imag = mlx_xpm_file_to_image(vars->mlx, "cara.xpm", &player->text.width, &player->text.height);
	player->steps = 0;
	player->x = 1;
	player->y = 1;
	player->show_name = 0;
}

int	main(void)
{
	t_vars	vars;
	t_player *player;

	player = &vars.player;
	int		*x;
	int		*y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, STEP * LARGURA, STEP * ALTURA, "Hello world!");
	init_player(player, &vars);
	draw_game(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
