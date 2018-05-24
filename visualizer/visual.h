/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:57:38 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/24 13:57:39 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

#include "../libft/libft.h"
#include <mlx.h>

# define MLX mlx->mlx_ptr
# define WIN mlx->win_ptr
# define LINE mlx->line
# define PLYR_X mlx->player_x
# define PLYR_O mlx->player_o

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	char 	*line;
	char 	*player_x;
	char	*player_o;
}				t_mlx;

void	drawing_net(int i, int j, t_mlx *mlx);

#endif
