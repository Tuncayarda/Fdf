/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:54:01 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/23 12:44:18 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->mlx.win, 2, (1L << 0), handle_keys, fdf);
	mlx_hook(fdf->mlx.win, 17, 0, close_window, fdf);
}

int	main(int an, char *args[])
{
	t_fdf	fdf;

	if (an != 2)
		terminate("Wrong File Entry!!!");
	init_map(&fdf.map);
	fdf.map.parse(&fdf.map, args[1]);
	init_mlx(&fdf.mlx);
	init_hooks(&fdf);
	fill_map(&fdf, EIGENGRAU);
	draw_map(&fdf, conf_map(&fdf.map));
	mlx_put_image_to_window(fdf.mlx.ptr, fdf.mlx.win, fdf.mlx.img, 0, 0);
	update_menu(&fdf);
	mlx_loop(fdf.mlx.ptr);
}
