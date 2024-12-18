/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:51:08 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/29 00:00:27 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "colors.h"
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define PI 3.14f
# define RAD 0.01745329251

# ifndef WIDTH
#  define WIDTH 3500
# endif

# ifndef HEIGHT
#  define HEIGHT 2300
# endif

# define SCALE 50.0f
# define MIN_SCALE 1.0f
# define MAX_SCALE 500.0f
# define MAX_Z_DIV 500.0f
# define MIN_Z_DIV 0.8f
# define TITLE "FDF"

typedef enum e_projection
{
	ISOMETRIC,
	DIMETRIC,
	TRIMETRIC,
	O_FREE,
	SPHERE
}				t_projection;

typedef enum e_color_profile
{
	NONE,
	TERRAIN
}				t_color_profile;

typedef enum e_li
{
	DX,
	DY,
	HIP,
	STEP,
	R,
	G,
	B,
	R_STEP,
	G_STEP,
	B_STEP
}				t_line_elems;

typedef struct s_resizable_arr
{
	size_t	count;
	size_t	type_size;
	size_t	max_count;
	void	*data;
	int		(*insert)(struct s_resizable_arr (*arr), void (*var));
	int		(*init)(struct s_resizable_arr (*arr), size_t type_size);
	int		(*free)(struct s_resizable_arr (*arr));
}				t_resizable_arr;

void	init_resizable_arr(t_resizable_arr *arr);

typedef union u_color
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

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	bool	is_visible;
	t_clr	color;
}				t_pt;

typedef struct s_map
{
	size_t			width;
	size_t			height;
	long			x_offset;
	long			y_offset;
	float			scale_val;
	float			z_div;
	float			angle_x;
	float			angle_y;
	float			angle_z;
	bool			isfilled;
	t_pt			*pts;
	t_projection	proj;
	t_color_profile	clr_prof;
	int				(*parse)(struct s_map *map, const char *path);
	int				(*scale)(struct s_map *map);
	int				(*push)(struct s_map *map);
	int				(*rotate)(struct s_map *map);
	int				(*colorize)(struct s_map *map);
}					t_map;
void	init_map(t_map	*map);

typedef struct s_mlx_v
{
	void	*ptr;
	void	*win;
	void	*img;
	int		*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx_v;

typedef struct s_fdf
{
	t_map	map;
	t_mlx_v	mlx;
}			t_fdf;

int		check_file(const char *path);
void	terminate(const char *msg);
void	init_mlx(t_mlx_v *mlx_v);
void	draw_line(t_fdf *fdf, t_pt p1, t_pt p2);
int		draw_map(t_fdf *fdf, t_map map);
t_map	conf_map(t_map *map);
int		handle_keys(int keycode, t_fdf *fdf);
void	fill_win(t_fdf	*fdf, int color);
int		close_window(t_fdf *fdf);
void	update_menu(t_fdf *fdf);
void	set_angles(t_map *map);
void	set_proj(t_map *map, t_projection projection);
void	draw_pix(t_fdf	*fdf, t_pt p);
int		draw_sphere(t_fdf *fdf, t_map map);
void	set_invisibles_pos(t_map *map);
long	ft_hexatoi(char *hex);
void	swap_pt(t_pt *a, t_pt *b);
void	fill_triangle(t_fdf *fdf, t_pt p1, t_pt p2, t_pt p3);

#endif
