/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:08:25 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/16 17:07:20 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "libft/libft.h"

# define X fill->x
# define Y fill->y
# define SYMBL fill->symbol

typedef struct	s_f
{
	int		x;
	int		y;
	char	symbol;
}				t_f;

#endif
