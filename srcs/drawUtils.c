/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:00:09 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 21:02:47 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pix(t_fdf	*fdf, t_pt p)
{
	if (p.x < WIDTH && p.y < HEIGHT && p.y >= 0 && p.x >= 0)
		fdf->mlx.img_data[(long)p.x + ((long)p.y * WIDTH)] = p.color.val;
}
