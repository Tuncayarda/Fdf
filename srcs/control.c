/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:00:15 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/24 00:46:54 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_prof_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_1)
		set_proj(&fdf->map, ISOMETRIC);
	if (keycode == XK_2)
		set_proj(&fdf->map, DIMETRIC);
	if (keycode == XK_3)
		set_proj(&fdf->map, TRIMETRIC);
	if (keycode == XK_4)
	{
		set_proj(&fdf->map, SPHERE);
		fdf->map.angle_x = 90;
		fdf->map.angle_y = 0;
		fdf->map.angle_z = 15;
	}
	if (keycode == XK_0)
	{
		fdf->map.angle_x = 45;
		fdf->map.angle_y = -45;
		fdf->map.angle_z = 0;
		set_proj(&fdf->map, O_FREE);
	}
	if (keycode == XK_n)
		fdf->map.clr_prof = NONE;
	if (keycode == XK_t)
		fdf->map.clr_prof = TERRAIN;
	set_angles(&fdf->map);
}

static void	handle_scale_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_z && fdf->map.scale_val * 1.2 <= MAX_SCALE)
		fdf->map.scale_val *= 1.2;
	if (keycode == XK_x && fdf->map.scale_val * 0.8 >= MIN_SCALE)
		fdf->map.scale_val *= 0.8;
	if (keycode == XK_c && fdf->map.z_div * 2.0f <= MAX_Z_DIV)
		fdf->map.z_div *= 2.0f;
	if (keycode == XK_v && fdf->map.z_div * 0.5f >= MIN_Z_DIV)
		fdf->map.z_div *= 0.5f;
}

static void	handle_push_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Up && fdf->map.proj == O_FREE)
		fdf->map.y_offset -= 100;
	if (keycode == XK_Down && fdf->map.proj == O_FREE)
		fdf->map.y_offset += 100;
	if (keycode == XK_Right && fdf->map.proj == O_FREE)
		fdf->map.x_offset += 100;
	if (keycode == XK_Left && fdf->map.proj == O_FREE)
		fdf->map.x_offset -= 100;
}

static void	handle_rot_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_q && fdf->map.proj == O_FREE && fdf->map.angle_z > -360)
		fdf->map.angle_z -= 5;
	if (keycode == XK_e && fdf->map.proj == O_FREE && fdf->map.angle_z < 360)
		fdf->map.angle_z += 5;
	if (keycode == XK_w && fdf->map.proj == O_FREE && fdf->map.angle_x < 360)
		fdf->map.angle_x += 5;
	if (keycode == XK_s && fdf->map.proj == O_FREE && fdf->map.angle_x > -360)
		fdf->map.angle_x -= 5;
	if (keycode == XK_a && fdf->map.proj == O_FREE && fdf->map.angle_y > -360)
		fdf->map.angle_y -= 5;
	if (keycode == XK_d && fdf->map.proj == O_FREE && fdf->map.angle_y < 360)
		fdf->map.angle_y += 5;
	if (keycode == XK_d && fdf->map.proj == SPHERE && fdf->map.angle_y < 135)
		fdf->map.angle_y += 45;
	if (keycode == XK_a && fdf->map.proj == SPHERE && fdf->map.angle_y > 0)
		fdf->map.angle_y -= 45;
}

int	handle_keys(int keycode, t_fdf *fdf)
{
	t_map	rtn;

	if (keycode == XK_Escape)
		exit (0);
	handle_push_keys(keycode, fdf);
	handle_rot_keys(keycode, fdf);
	handle_scale_keys(keycode, fdf);
	handle_prof_keys(keycode, fdf);
	fill_map(fdf, EIGENGRAU);
	rtn = conf_map(&fdf->map);
	if (rtn.pts == NULL)
		terminate("Allocation Fail!!!");
	draw_map(fdf, rtn);
	free(rtn.pts);
	mlx_put_image_to_window(fdf->mlx.ptr, fdf->mlx.win, fdf->mlx.img, 0, 0);
	update_menu(fdf);
}
