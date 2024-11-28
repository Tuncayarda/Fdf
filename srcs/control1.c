/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:02:31 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/29 00:05:03 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_fill_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_f)
	{
		if (fdf->map.isfilled)
			fdf->map.isfilled = false;
		else
			fdf->map.isfilled = true;
	}
}
