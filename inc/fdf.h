/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:51:08 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 20:46:59 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "colors.h"
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>

# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define PI 3.14f
# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "FDF"

typedef	struct	s_resizable_arr
{
	size_t	count;
	size_t	type_size;
	size_t	max_count;
	void	*data;
	bool	(*init)(struct	s_resizable_arr	*arr, size_t type_size);
	bool	(*insert)(struct	s_resizable_arr	*arr, void *var);
	bool	(*free)(struct	s_resizable_arr	*arr);
}				t_resizable_arr;
void	init_resizable_arr(t_resizable_arr *arr);

typedef union	u_color
{
	struct 
	{
		__uint8_t	b;
		__uint8_t	g;
		__uint8_t	r;
		__uint8_t	a;
	};
	__uint32_t		val;
}				t_clr;

typedef	struct	s_point
{
	float	x;
	float	y;
	float	z;
	t_clr	color;
}				t_pt;

typedef struct	s_map
{
	size_t	width;
	size_t	height;
	t_pt	*pts;

	bool	(*parse)(struct s_map *map, const char *path);
}				t_map;
void	init_map(t_map	*map);

typedef struct	s_vars
{
	t_map	*map;
}				t_vars;

__uint32_t	ft_hexatoi(char *hex);
bool		check_file(const char *path);

#endif
