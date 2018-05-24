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

static void	check_input(t_mlx *mlx)
{
	int i;
	int	n;

	i = 0;
	while (i < 9)
	{
		n = 7;
		get_next_line(0, &LINE);
		if (ft_strstr(LINE, "launched"))
		{
			if (ft_strchr(&LINE[n], '/'))
			{
				while (LINE[n] != '/')
					n++;
			}
			if (i > 6)
				PLYR_X = ft_strdup(&LINE[n + 1]);
			else
				PLYR_O = ft_strdup(&LINE[n + 1]);
		}
		free(LINE);
		i++;
	}
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
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	mlx = malloc(sizeof(t_mlx));
	LINE = NULL;
	check_input(mlx);
	get_next_line(0, &LINE);
	i = atoi(&LINE[8]);
	j = atoi(&LINE[8 + ft_count(i, 10)]);
	free(LINE);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1000, 1000, "FILLER");
	drawing_players(mlx);
	mlx_string_put(MLX, WIN, 500, 900, 0xFFFFFF, "Press SPACE to start the game!");
	drawing_net(i, j, mlx);
	mlx_hook(WIN, 2, 0, key_hook, mlx);
	mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
	mlx_loop(MLX);
	return (0);
}