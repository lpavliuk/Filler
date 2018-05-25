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

void		finish(t_mlx *mlx)
{
	char *o;
	char *x;

	o = ft_strdup(&LINE[10]);
	free(LINE);
	get_next_line(0, &LINE);
	x = strdup(&LINE[10]);
	free(LINE);
	mlx_clear_window(MLX, WIN);
	mlx_string_put(MLX, WIN, 450, 300, 0xFFD700, "GAME");
	mlx_string_put(MLX, WIN, 500, 300, 0xA52A2A, "OVER");
	mlx_string_put(MLX, WIN, 400, 400, 0xFFD700, "Player O: ");
	mlx_string_put(MLX, WIN, 500, 400, 0xFFD700, o);
	mlx_string_put(MLX, WIN, 400, 450, 0xA52A2A, "Player X: ");
	mlx_string_put(MLX, WIN, 500, 450, 0xA52A2A, x);
}

int			start_game(t_mlx *mlx)
{
	while (get_next_line(0, &LINE) > 0)
	{
		if (ft_strstr(LINE, "Plateau"))
		{
			free(LINE);
			write_map(mlx);
			mlx_clear_window(MLX, WIN);
			drawing_players(mlx);
			drawing_net(mlx);
			drawing_game(mlx);
			ft_stralldel(MAP, I + 1);
			free(MAP);
			break ;
		}
		else if (ft_strstr(LINE, "=="))
			finish(mlx);
		else
			free(LINE);
	}
	return (0);
}

static int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	else if (keycode == 49)
		mlx_loop_hook(MLX, start_game, mlx);
	return (0);
}

static int	exit_x(int keycode)
{
	exit(0);
}

int			main(void)
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
	write_map(mlx);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1000, 1000, "FILLER");
	drawing_players(mlx);
	mlx_string_put(MLX, WIN, 350, 800, 0xFFFFFF, "Press SPACE ");
	mlx_string_put(MLX, WIN, 475, 800, 0xFFFFFF, "to start the game!");
	drawing_net(mlx);
	drawing_game(mlx);
	mlx_hook(WIN, 2, 0, key_hook, mlx);
	mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
	mlx_loop(MLX);
	freeshka(mlx);
	return (0);
}
