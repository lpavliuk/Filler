/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:08:25 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/16 18:58:31 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "libft/libft.h"

# define X fill->x
# define Y fill->y
# define X_F fill->x_f
# define Y_F fill->y_f
# define NUM fill->num
# define SYMBL fill->symbol
# define LINE fill->line

typedef struct	s_f
{
	int		x;
	int		y;
	int		*x_f;
	int		*y_f;
	int		num;
	char	symbol;
	char	*line;
}				t_f;

#endif
