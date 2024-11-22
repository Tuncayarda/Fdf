/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:34:12 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/22 19:34:49 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_rot_matrix(float matrix[4][4], float x, float y, float z)
{
	matrix[0][0] = cosf(y) * cosf(z);
	matrix[1][0] = cosf(y) * sinf(z);
	matrix[2][0] = -sinf(y);
	matrix[3][0] = 0;
	matrix[0][1] = (sinf(x) * sinf(y) * cosf(z)) - (cosf(x) * sinf(z));
	matrix[1][1] = (sinf(x) * sinf(y) * sinf(z)) + (cosf(x) * cosf(z));
	matrix[2][1] = (sinf(x) * cosf(y));
	matrix[3][1] = 0;
	matrix[0][2] = (cosf(x) * sinf(y) * cosf(z)) + (sinf(x) * sinf(z));
	matrix[1][2] = (cosf(x) * sinf(y) * sinf(z)) - (sinf(x) * cosf(z));
	matrix[2][2] = cosf(x) * cosf(y);
	matrix[3][2] = 0;
	matrix[0][3] = 0;
	matrix[1][3] = 0;
	matrix[2][3] = 0;
	matrix[3][3] = 1;
}

