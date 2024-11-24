/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:54:17 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/24 19:35:42 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_map(t_fdf *fdf, t_map map)
{
	size_t	i;

	i = 0;
	while (i < map.width * map.height)
	{
		if (map.pts[i].is_visible)
		{
			if ((i + 1) % map.width != 0)
				draw_line(fdf, map.pts[i], map.pts[i + 1]);
			if (i < map.width * map.height - map.width)
				draw_line(fdf, map.pts[i], map.pts[i + map.width]);
		}
		i++;
	}
	return (true);
}
