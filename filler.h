/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:08:25 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/17 15:01:32 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "libft/libft.h"

# define X fill->size_x_map
# define Y fill->size_y_map
# define MAP fill->map
# define SIZE_F_X fill->size_figure_x
# define SIZE_F_Y fill->size_figure_y
# define X_F fill->x_figure
# define Y_F fill->y_figure
# define NUM fill->num
# define SYMBL fill->symbol
# define LINE fill->line

typedef struct	s_f
{
	int		size_x_map;
	int		size_y_map;
	int		size_figure_x;
	int		size_figure_y;
	int		*x_figure;
	int		*y_figure;
	int		num;
	char	symbol;
	char	**map;
	char	*line;
}				t_f;

void 			check_input(t_f *fill);

#endif
