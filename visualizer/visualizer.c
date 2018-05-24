/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:19:25 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/23 17:19:27 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	return (0);
}

static int exit_x(int keycode)
{
	exit (0);
}

int main(void)
{
	t_mlx	*mlx;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	mlx = malloc(sizeof(t_mlx));
	LINE = NULL;
	get_next_line(0, &LINE);
	i = atoi(&LINE[0]);
	j = atoi(&LINE[ft_count(i, 10)]);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1000, 1000, "FILLER");
	drawing_net(i, j, mlx);
	mlx_hook(WIN, 2, 0, key_hook, mlx);
	mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
	mlx_loop(MLX);
	return (0);
}