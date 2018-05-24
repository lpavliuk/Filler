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

static void	draw_x(t_mlx *mlx)
{
	int x;
	int y;
	int a;

	x = 250;
	a = 1;
	while (x < (250 + ((500 / J) * J)))
	{
		y = 250;
		if (x == (250 + ((500 / J) * a)))
		{
			while (y < (250 + ((500 / I) * I)))
				mlx_pixel_put(MLX, WIN, x, y++, 0xFFFFFF);
			a++;
		}
		mlx_pixel_put(MLX, WIN, x++, y, 0xFFFFFF);
	}
	while (y < (250 + ((500 / I) * I)))
		mlx_pixel_put(MLX, WIN, x, y++, 0xFFFFFF);
}

void		drawing_net(t_mlx *mlx)
{
	int		x;
	int		y;
	int		a;

	x = 250;
	y = 250;
	a = 1;
	draw_x(mlx);
	while (y < (250 + ((500 / I) * I)))
	{
		if (y == (250 + ((500 / I) * a)))
		{
			while (x < (250 + ((500 / J) * J)))
				mlx_pixel_put(MLX, WIN, x++, y, 0xFFFFFF);
			x = 250;
			a++;
		}
		mlx_pixel_put(MLX, WIN, x, y++, 0xFFFFFF);
	}
	while (x < (250 + ((500 / J) * J)))
		mlx_pixel_put(MLX, WIN, x++, y, 0xFFFFFF);
}
