/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:54:59 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/22 23:58:05 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *fdf)
{
	free(fdf->map.pts);
	mlx_destroy_image(fdf->mlx.ptr, fdf->mlx.img);
	mlx_destroy_window(fdf->mlx.ptr, fdf->mlx.win);
	free(fdf->mlx.ptr);
	exit(0);
}
