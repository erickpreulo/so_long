/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:31:21 by egomes            #+#    #+#             */
/*   Updated: 2021/10/01 19:53:53 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>

# define END 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define UP2 126
# define DOWN2 125
# define LEFT2 123
# define RIGHT2 124
# define BUFFER_SIZE 10
# define STEP 64
# define LARGURA 20
# define ALTURA 13

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_texture
{
	void	*imag;
	void	*imag_esq;
	int		width;
	int		height;
	int		left;
	int		x;
	int		y;
	int		x1;
	int		y1;
}				t_texture;

typedef struct s_maps
{
	char	*buf;
	char	*map;
	char	*line;
	int		width;
	int		height;
	int		i;
	int		c;
	int		e;
	int		p;
	int		p2;
	int		s;
	int		s2;
	int		x2;
	int		x3;
	int		x4;
}				t_maps;

typedef struct s_coins
{
	void	*imag;
	int		width;
	int		height;
	int		count;
}				t_coins;

typedef struct s_player
{
	t_texture	text;
	int			p;
	int			x;
	int			y;
	int			steps;
	int			show_name;
}				t_player;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			i;
	int			j;
	int			x;
	int			savei;
	int			savej;
	t_texture	wall;
	t_texture	gras;
	t_texture	ex;
	t_player	player;
	t_player	player2;
	t_player	enemi;
	t_player	enemi1;
	t_player	enemi2;
	t_maps		maps;
	t_coins		coins;
	t_texture	portal;
	int64_t		last_update;
}				t_vars;

int		main(int ac, char **av);
char	*ft_itoa(int n);
int		get_next_line(int fd, char **line);
void	init_map(t_vars *vars, char *map);
char	*ft_strcat(char *dest, const char *src);
int		ft_strlen(char *s);
void	draw_game(t_vars *vars);
int		enemi(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	make_move(int *pos_player, int *pos_enemi, int increment, t_vars *vars);
void	caught(t_vars *vars);
void	print(t_vars *vars);
void	validade_all_map(t_vars *vars);
void	validate_line(t_vars *vars);
void	validate_first_line(t_vars *vars, int ret);
int		player2(t_vars *vars, int keycode, int i);
int		player1(t_vars *vars, int keycode, int j);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dest, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_has_nl(char *str);
char	*ft_newstr(size_t size);

#endif
