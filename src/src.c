/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:48:18 by egomes            #+#    #+#             */
/*   Updated: 2021/09/29 17:19:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t			len;
	size_t			i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = 0;
	return (dest);
}

void	print(t_vars *vars)
{
	char	*steps;

	steps = ft_itoa(vars->player.steps);
	if (vars->player.show_name)
	{
		mlx_string_put(vars->mlx, vars->win, vars->player.x * STEP + 10,
			vars->player.y * STEP - 15, 0xff0000, "P1");
		mlx_string_put(vars->mlx, vars->win, vars->player.x * STEP + 35,
			vars->player.y * STEP - 15, 0xff0000, steps);
	}
	if (vars->player2.show_name && vars->player.show_name)
		mlx_string_put(vars->mlx, vars->win, vars->player2.x * STEP + 28,
			vars->player2.y * STEP - 15, 0x00FF00, "P2");
	vars->player.text.left = 0;
	vars->player2.text.left = 0;
	vars->enemi.p = 0;
	vars->enemi1.p = 0;
	vars->enemi2.p = 0;
	free(steps);
}

void	caught(t_vars *vars)
{
	if (vars->enemi.x == vars->player.x && vars->enemi.y == vars->player.y
		|| vars->enemi1.x == vars->player.x && vars->enemi1.y == vars->player.y
		|| vars->enemi2.x == vars->player.x && vars->enemi2.y == vars->player.y
		|| vars->enemi.x == vars->player2.x
		&& vars->enemi.y == vars->player2.y
		|| vars->enemi1.x == vars->player2.x
		&& vars->enemi1.y == vars->player2.y
		|| vars->enemi2.x == vars->player2.x
		&& vars->enemi2.y == vars->player2.y)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("CAUGHT!!!\n");
		free(vars->maps.buf);
		exit(0);
	}
}
