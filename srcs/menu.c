/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:17:07 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/23 14:06:45 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_angles(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 40, ORANGE, "X ROTATION:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 40, WHITE, ft_itoa((int)fdf->map.angle_x));
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 60, ORANGE, "Y ROTATION:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 60, WHITE, ft_itoa((int)fdf->map.angle_y));
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 80, ORANGE, "Z ROTATION:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 80, WHITE, ft_itoa((int)fdf->map.angle_z));
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 100, ORANGE, "----------------------");
}

static void	update_offsets(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 120, ORANGE, "X OFFSET:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 120, WHITE, ft_itoa((int)fdf->map.x_offset));
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 140, ORANGE, "Y OFFSET:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 140, WHITE, ft_itoa((int)fdf->map.y_offset));
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 160, ORANGE, "----------------------");
}

static void	update_profiles(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 180, ORANGE, "PROJECTION:");
	if (fdf->map.proj == ISOMETRIC)
		mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
			80, 180, WHITE, "ISOMETRIC");
	if (fdf->map.proj == DIMETRIC)
		mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
			80, 180, WHITE, "DIMETRIC");
	if (fdf->map.proj == TRIMETRIC)
		mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
			80, 180, WHITE, "TRIMETRIC");
	if (fdf->map.proj == SPHERE)
		mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
			80, 180, WHITE, "SPHERE");
	if (fdf->map.proj == O_FREE)
		mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
			80, 180, WHITE, "FREE");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 200, ORANGE, "COLOR PRFL:");
	if (fdf->map.clr_prof == NONE)
		mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
			80, 200, WHITE, "NONE");
	if (fdf->map.clr_prof == TERRAIN)
		mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
			80, 200, WHITE, "TERRAIN");
}

static void	update_mapinfo(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 220, ORANGE, "WIDTH:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 220, WHITE, ft_itoa((int)(fdf->map.width * fdf->map.scale_val)));
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 240, ORANGE, "HEIGHT:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 240, WHITE, ft_itoa((int)(fdf->map.height * fdf->map.scale_val)));
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 260, ORANGE, "POINTS:");
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		80, 260, WHITE, ft_itoa((int)(fdf->map.height * fdf->map.width)));
}

void	update_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.ptr, fdf->mlx.win,
		10, 20, ORANGE, "----------FDF---------");
	update_angles(fdf);
	update_offsets(fdf);
	update_profiles(fdf);
	update_mapinfo(fdf);
}
