/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:00:09 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/23 18:12:26 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pix(t_fdf	*fdf, t_pt p)
{
	if (p.x < WIDTH && p.y < HEIGHT && p.y >= 0 && p.x >= 0)
		fdf->mlx.img_data[(long)p.x + ((long)p.y * WIDTH)] = p.color.val;
}

static float	get_high_d(float dx, float dy)
{
	if (fabs(dx) > fabs(dy))
		return (fabs(dx));
	else
		return (fabs(dy));
}

void	draw_line(t_fdf *fdf, t_pt p1, t_pt p2)
{
	float	arr[10];

	arr[DX] = p2.x - p1.x;
	arr[DY] = p2.y - p1.y;
	arr[HIP] = sqrtf(arr[DX] * arr[DX] + arr[DY] * arr[DY]);
	arr[R_STEP] = (p2.color.r - p1.color.r) / arr[HIP];
	arr[G_STEP] = (p2.color.g - p1.color.g) / arr[HIP];
	arr[B_STEP] = (p2.color.b - p1.color.b) / arr[HIP];
	arr[R] = p1.color.r;
	arr[G] = p1.color.g;
	arr[B] = p1.color.b;
	while (arr[HIP]-- > 0)
	{
		draw_pix(fdf, p1);
		if ((long)p1.x != (long)p2.x)
			p1.x += arr[DX] / get_high_d(arr[DX], arr[DY]);
		if ((long)p1.y != (long)p2.y)
			p1.y += arr[DY] / get_high_d(arr[DX], arr[DY]);
		arr[R] += arr[R_STEP];
		arr[G] += arr[G_STEP];
		arr[B] += arr[B_STEP];
		p1.color.r = arr[R];
		p1.color.g = arr[G];
		p1.color.b = arr[B];
	}
}

void	fill_map(t_fdf	*fdf, int color)
{
	size_t	i;

	i = 0;
	if (fdf->mlx.img_data)
	{
		while (i < WIDTH * HEIGHT)
		{
			fdf->mlx.img_data[i] = EIGENGRAU;
			i++;
		}
	}
}
