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

static int key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
//	else if (keycode == 49)
	//		start_game(mlx);
	return (0);
}

static int exit_x(int keycode)
{
	exit (0);
}

static void	drawing_players(t_mlx *mlx)
{
	mlx_string_put(MLX, WIN, 150, 100, 0xFFD700, "Player O: ");
	mlx_string_put(MLX, WIN, 250, 100, 0xFFD700, PLYR_O);
	mlx_string_put(MLX, WIN, 150, 150, 0xA52A2A, "Player X: ");
	mlx_string_put(MLX, WIN, 250, 150, 0xA52A2A, PLYR_X);
}



int main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	LINE = NULL;
	I = 0;
	J = 0;
	check_input(mlx);
	get_next_line(0, &LINE);
	I = atoi(&LINE[8]);
	J = atoi(&LINE[8 + ft_count(I, 10)]);
	free(LINE);
	write_map(I, J, mlx);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1000, 1000, "FILLER");
	drawing_players(mlx);
	mlx_string_put(MLX, WIN, 350, 800, 0xFFFFFF, "Press SPACE to start the game!");
	drawing_net(I, J, mlx);
	drawing_game(mlx);
	mlx_hook(WIN, 2, 0, key_hook, mlx);
	mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
	mlx_loop(MLX);
	ft_stralldel(MAP, I + 1);
	free(MAP);
	free(PLYR_O);
	free(PLYR_X);
	free(mlx);
	return (0);
}