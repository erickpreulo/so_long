/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:31:00 by egomes            #+#    #+#             */
/*   Updated: 2021/09/11 17:18:45 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int x;
int y;

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


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i;
	int j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);

	// i = -1;
	// while (++i < 400)
	// {
	// 	j = -1;
	// 	while (++j < 400)
	// 		my_mlx_pixel_put(&img, i, j, 0x00ffffff);
	// }

	x = 180;
	y = 150;

	i = x;
	while (++i < x + 50)
	{
		j = y;
		while (++j < y + 50)
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
