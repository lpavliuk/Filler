/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_net.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:27:29 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/24 14:27:30 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	draw_x(int i, int j, t_mlx *mlx)
{
	int x;
	int y;
	int a;

	x = 250;
	a = 1;
	while (x < (250 + ((500/j) * j)))
	{
		y = 250;
		if (x == (250 + ((500/j) * a)))
		{
			while (y < (250 + ((500/i) * i)))
				mlx_pixel_put(MLX, WIN, x, y++, 0xFFFFFF);
			a++;
		}
		mlx_pixel_put(MLX, WIN, x++, y, 0xFFFFFF);
	}
	while (y < (250 + ((500/i) * i)))
		mlx_pixel_put(MLX, WIN, x, y++, 0xFFFFFF);
}

void		drawing_net(int i, int j, t_mlx *mlx)
{
	int		x;
	int		y;
	int 	a;

	x = 250;
	y = 250;
	a = 1;
	draw_x(i, j, mlx);
	while (y < (250 + ((500/i) * i)))
	{
		if (y == (250 + ((500/i) * a)))
		{
			while (x < (250 + ((500/j) * j)))
				mlx_pixel_put(MLX, WIN, x++, y, 0xFFFFFF);
			x = 250;
			a++;
		}
		mlx_pixel_put(MLX, WIN, x, y++, 0xFFFFFF);
	}
	while (x < (250 + ((500/j) * j)))
		mlx_pixel_put(MLX, WIN, x++, y, 0xFFFFFF);
}
