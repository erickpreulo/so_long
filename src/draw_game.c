/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:49:57 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 14:26:26 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void		init_imag(t_vars * vars, t_texture *wall, t_texture *gras, t_texture *ex, t_player *player)
{
	wall->imag = mlx_xpm_file_to_image(vars->mlx, "xpm/texter.xpm", &wall->width, &wall->height);
	gras->imag = mlx_xpm_file_to_image(vars->mlx, "xpm/gras.xpm", &gras->width, &gras->height);
	ex->imag = mlx_xpm_file_to_image(vars->mlx, "xpm/exit.xpm", &ex->width, &ex->height);
	vars->enemi.text.imag = mlx_xpm_file_to_image(vars->mlx, "xpm/enemi_dir.xpm", &vars->enemi.text.width, &vars->enemi.text.height);
	vars->enemi.text.imag_esq = mlx_xpm_file_to_image(vars->mlx, "xpm/enemi_esq.xpm", &vars->enemi.text.width, &vars->enemi.text.height);
	vars->coins.imag = mlx_xpm_file_to_image(vars->mlx, "xpm/coins.xpm", &vars->coins.width, &vars->coins.height);
	vars->portal.imag = mlx_xpm_file_to_image(vars->mlx, "xpm/portal.xpm", &vars->portal.width, &vars->portal.height);
}

void		draw_game(t_vars *vars)
{
	t_texture	wall;
	t_texture	gras;
	t_texture	ex;
	t_player *player;
	char	*steps;
	int len;
	int i;
	int j;
	int x;
	int y;

	player = &vars->player;
	init_imag(vars, &wall, &gras, &ex, player);
	len = vars->maps.width * vars->maps.height;
	i = 0;
	while (i < len)
	{
		x = i % vars->maps.width;
		y = i / vars->maps.width;
		if (vars->enemi.x == player->x && vars->enemi.y == player->y
			|| vars->enemi1.x == player->x && vars->enemi1.y == player->y
			|| vars->enemi2.x == player->x && vars->enemi2.y == player->y
			|| vars->enemi.x == vars->player2.x && vars->enemi.y == vars->player2.y
			|| vars->enemi1.x == vars->player2.x && vars->enemi1.y == vars->player2.y
			|| vars->enemi2.x == vars->player2.x && vars->enemi2.y == vars->player2.y)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			printf("CAUGHT!!!\n");
			free(vars->maps.buf);
			exit(0);
		}
		if ((x == vars->player.x && y == vars->player.y && vars->maps.buf[i] == 'C')
			|| (x == vars->player2.x && y == vars->player2.y && vars->maps.buf[i] == 'C'))
		{
			vars->coins.count--;
			vars->maps.buf[i] = '0';
		}
		if (vars->maps.buf[i] == '1')
	 		mlx_put_image_to_window(vars->mlx, vars->win, wall.imag, x * STEP, y * STEP);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, gras.imag, x * STEP, y * STEP);
		if (vars->maps.buf[i] == 'S' || vars->maps.buf[i] == 's')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->portal.imag, x * STEP, y * STEP);
		if (x == player->x && y == player->y  && vars->player.text.left == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, player->text.imag_esq, x * STEP, y * STEP);
		else if (x == player->x && y == player->y)
			mlx_put_image_to_window(vars->mlx, vars->win, player->text.imag, x * STEP, y * STEP);
		if (vars->player2.show_name)
		{
			if (x == vars->player2.x && y == vars->player2.y  && vars->player2.text.left == 1)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.text.imag_esq, x * STEP, y * STEP);
			else if (x == vars->player2.x && y == vars->player2.y)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.text.imag, x * STEP, y * STEP);
		}
		if (vars->maps.buf[i] == 'C')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->coins.imag, x * STEP, y * STEP);
		if (vars->maps.buf[i] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, ex.imag, x * STEP, y * STEP);
		if (x == vars->enemi.x && y == vars->enemi.y && vars->x >= 1 && vars->enemi.p != 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enemi.text.imag, x * STEP, y * STEP);
		else if (x == vars->enemi.x && y == vars->enemi.y && vars->x >= 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enemi.text.imag_esq, x * STEP, y * STEP);
		if (x == vars->enemi1.x && y == vars->enemi1.y && vars->x >= 1 && vars->enemi1.p != 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enemi.text.imag, x * STEP, y * STEP);
		else if (x == vars->enemi1.x && y == vars->enemi1.y && vars->x >= 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enemi.text.imag_esq, x * STEP, y * STEP);
		if (x == vars->enemi2.x && y == vars->enemi2.y && vars->x >= 1 && vars->enemi2.p != 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enemi.text.imag, x * STEP, y * STEP);
		else if (x == vars->enemi2.x && y == vars->enemi2.y && vars->x >= 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enemi.text.imag_esq, x * STEP, y * STEP);
		i++;
	}
	//mlx_string_put(vars->mlx, vars->win, 100, 100, 0xffffff, ft_itoa(vars->coins.count));
	steps = ft_itoa(player->steps);
	if (player->show_name)
	{
		mlx_string_put(vars->mlx, vars->win, player->x * STEP + 10, player->y * STEP - 15, 0xff0000, "P1");
		mlx_string_put(vars->mlx, vars->win, player->x * STEP + 35, player->y * STEP - 15, 0xff0000, steps);
	}
	if (vars->player2.show_name && player->show_name)
		mlx_string_put(vars->mlx, vars->win, vars->player2.x * STEP + 28, vars->player2.y * STEP - 15, 0x00FF00, "P2");
	vars->player.text.left = 0;
	vars->player2.text.left = 0;
	vars->enemi.p = 0;
	vars->enemi1.p = 0;
	vars->enemi2.p = 0;
	free(steps);
}
