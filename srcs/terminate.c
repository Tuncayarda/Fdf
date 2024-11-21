/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:04:51 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 21:05:05 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	terminate(const char *msg)
{
	if (!msg)
		ft_printf("Error: %s\n", strerror(errno));
	else
		ft_printf("Error: %s\n", msg);
	exit(1);
}
