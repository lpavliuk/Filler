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
# define FIGURE fill->figure
# define MIN_X fill->min_x
# define MIN_Y fill->min_y
# define MAX_X fill->max_x
# define MAX_Y fill->max_y
# define SYMBL fill->symbol
# define LINE fill->line

typedef struct	s_f
{
	int		size_x_map;
	int		size_y_map;
	int		size_figure_x;
	int		size_figure_y;
	char	**figure;
	int		min_x;
	int		min_y;
	int 	max_x;
	int 	max_y;
	char	symbol;
	char	**map;
	char	*line;
}				t_f;

void 			check_input(t_f *fill);
void		    write_map(t_f *fill);

#endif
