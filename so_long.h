/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:31:21 by egomes            #+#    #+#             */
/*   Updated: 2021/09/14 03:10:59 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

#define STEP 64
#define LARGURA 6
#define ALTURA 13

int		main(void);
char	*ft_itoa(int n);

#endif