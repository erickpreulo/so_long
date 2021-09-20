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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		i;
	int		j;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//int	render_next_frame(void *YourStruct);

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == UP)
	{
		printf("UP\n");
		if (vars->i > 0)
			vars->i--;
		return (1);
	}
	if (keycode == DOWN)
	{
		printf("DOWN\n");
		return (1);
	}
	if (keycode == LEFT)
	{
		printf("LEFT\n");
		return (1);
	}
	if (keycode == RIGHT)
	{
		printf("RIGHT\n");
		return (1);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		*x;
	int		*y;
	int		i;
	int		j;
	int		count;

	count = 0;
	vars.i = 50;
	vars.j = 50;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	i = 100;
	while(i >= 0)
	{
		j = count;
		while (j <= 100)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i--;
		count++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, vars.i, vars.j);
	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}