/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:00:15 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/22 21:42:47 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_proj_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_1)
		fdf->map.proj = ISOMETRIC;
	if (keycode == XK_2)
		fdf->map.proj = DIMETRIC;
	if (keycode == XK_3)
		fdf->map.proj = TRIMETRIC;
	if (keycode == XK_0)
		fdf->map.proj = FREE;
}

void	handle_scale_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_z && fdf->map.scale_val * 1.2 <= MAX_SCALE)
		fdf->map.scale_val *= 1.2;
	if (keycode == XK_x && fdf->map.scale_val * 0.8 >= MIN_SCALE)
		fdf->map.scale_val *= 0.8;
	if (keycode == XK_c && fdf->map.z_div * 2 <= MAX_Z_DIV)
		fdf->map.z_div *= 2;
	if (keycode == XK_v && fdf->map.z_div * 0.5f >= MIN_Z_DIV)
		fdf->map.z_div *= 0.5;
}

void	handle_push_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Up)
		fdf->map.y_offset -= 100;
	if (keycode == XK_Down)
		fdf->map.y_offset += 100;
	if (keycode == XK_Right)
		fdf->map.x_offset += 100;
	if (keycode == XK_Left)
		fdf->map.x_offset -= 100;
}

void	handle_rot_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_q)
		fdf->map.angle_z -= 5;
	if (keycode == XK_e)
		fdf->map.angle_z += 5;
	if (keycode == XK_w)
		fdf->map.angle_x += 5;
	if (keycode == XK_s)
		fdf->map.angle_x -= 5;
	if (keycode == XK_a)
		fdf->map.angle_y -= 5;
	if (keycode == XK_d)
		fdf->map.angle_y += 5;
}

int	handle_keys(int keycode, t_fdf *fdf)
{
	t_map	rtn;

	if (keycode == XK_Escape)
		exit (0);
	handle_push_keys(keycode, fdf);
	handle_rot_keys(keycode, fdf);
	handle_scale_keys(keycode, fdf);
	handle_proj_keys(keycode, fdf);
	fill_map(fdf, EIGENGRAU);
	rtn = conf_map(&fdf->map);
	draw_map(fdf, rtn);
	free(rtn.pts);
	mlx_put_image_to_window(fdf->mlx.ptr, fdf->mlx.win, fdf->mlx.img, 0, 0);
}