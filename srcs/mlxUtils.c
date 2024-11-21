/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:04:20 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 21:11:39 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mlx_vars(t_mlx_v *mlx_v)
{
	mlx_v->ptr = mlx_init();
	if (!mlx_v->ptr)
		terminate("MLX init failure!!!");
	mlx_v->win = mlx_new_window(mlx_v->ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx_v->win)
	{
		free(mlx_v->ptr);
		terminate("MLX window init failure!!!");
	}
	mlx_v->img = mlx_new_image(mlx_v->ptr, WIDTH, HEIGHT);
	if (!mlx_v->img)
	{
		free(mlx_v->ptr);
		free(mlx_v->win);
		terminate("MLX image init failure!!!");
	}
	mlx_v->img_data = (int *)mlx_get_data_addr(mlx_v->img, &mlx_v->bpp,
			&mlx_v->size_line, &mlx_v->endian);
	if (!mlx_v->img_data)
	{
		free(mlx_v->img);
		free(mlx_v->ptr);
		free(mlx_v->win);
		terminate("MLX image data init failure!!!");
	}
}

void	init_mlx(t_mlx_v *mlx_v)
{
	init_mlx_vars(mlx_v);
}
