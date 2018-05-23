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

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

int		ft_count(int n, short int base)
{
	int c;

	if (n == -2147483648)
		return (11);
	if (n >= 0)
		c = 1;
	else if (n < 0)
		c = 2;
	while (n / base != 0)
	{
		n = n / base;
		c++;
	}
	return (c);
}

int main(void)
{
	int		i;
	int 	j;
	int		x;
	int		y;
	int 	a;
	char	line[25];
	void	*mlx_ptr;
	void	*win_ptr;

	read(0, line, 25);
	i = atoi(&line[0]);
	j = atoi(&line[ft_count(i, 10)]);
	x = j/4;
	y = i/4;
	a = 1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, j, i, "AWESOME WINDOW!");
	while (x < (j/2 + j/4))
	{
		if (x == (j / 4 + ((j/2) / (j/100)) * a))
		{
			while (y < (i / 2 + i / 4))
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y++, 0xFFFFFF);
			}
			y = i / 4;
			a++;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, x++, y, 0xFFFFFF);
	}
	while (y < (i/2 + i/4))
		mlx_pixel_put(mlx_ptr, win_ptr, x, y++, 0xFFFFFF);
	x = j/4;
	y = i/4;
	a = 1;
	while (y < (i / 2 + i / 4))
	{
		if (y == (i / 4 + ((i / 2) / (i/100)) * a))
		{
			while (x < (j / 2 + j / 4))
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x++, y, 0xFFFFFF);
			}
			x = j / 4;
			a++;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, x, y++, 0xFFFFFF);
	}
	while (x < (j/2 + j/4))
		mlx_pixel_put(mlx_ptr, win_ptr, x++, y, 0xFFFFFF);
	mlx_loop(mlx_ptr);
	return (0);
}