/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:28:28 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/24 18:28:30 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		drawing_players(t_mlx *mlx)
{
	mlx_string_put(MLX, WIN, 150, 100, 0xFFD700, "Player O: ");
	mlx_string_put(MLX, WIN, 250, 100, 0xFFD700, PLYR_O);
	mlx_string_put(MLX, WIN, 150, 150, 0xA52A2A, "Player X: ");
	mlx_string_put(MLX, WIN, 250, 150, 0xA52A2A, PLYR_X);
}

static void	draw_x(int a, int b, t_mlx *mlx)
{
	int x;
	int y;

	x = (250 + ((((500 / J) * b)) + 1));
	while (x < (250 + ((((500 / J) * (b + 1))))))
	{
		y = (250 + ((((500 / I) * a)) + 1));
		while (y < (250 + ((((500 / I) * (a + 1) - 1)))))
			mlx_pixel_put(MLX, WIN, x, y++, 0xA52A2A);
		mlx_pixel_put(MLX, WIN, x++, y, 0xA52A2A);
	}
}

static void	draw_o(int a, int b, t_mlx *mlx)
{
	int x;
	int y;

	x = (250 + ((((500 / J) * b)) + 1));
	while (x < (250 + ((((500 / J) * (b + 1))))))
	{
		y = (250 + ((((500 / I) * a)) + 1));
		while (y < (250 + ((((500 / I) * (a + 1) - 1)))))
			mlx_pixel_put(MLX, WIN, x, y++, 0xFFD700);
		mlx_pixel_put(MLX, WIN, x++, y, 0xFFD700);
	}
}

void		drawing_game(t_mlx *mlx)
{
	int a;
	int b;
	int x;
	int y;

	a = 0;
	x = -1;
	while (++x < I)
	{
		y = -1;
		b = 0;
		while (++y < J)
		{
			if (MAP[x][y] == 'x' || MAP[x][y] == 'X')
				draw_x(a, b, mlx);
			else if (MAP[x][y] == 'o' || MAP[x][y] == 'O')
				draw_o(a, b, mlx);
			b++;
		}
		a++;
	}
}
