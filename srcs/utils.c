/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:13 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/28 23:52:57 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long	hex_loop(long *result, char *hex)
{
	*result <<= 4;
	if (*hex >= '0' && *hex <= '9')
		*result += *hex - '0';
	else if (*hex >= 'a' && *hex <= 'f')
		*result += *hex - 'a' + 10;
	else if (*hex >= 'A' && *hex <= 'F')
		*result += *hex - 'A' + 10;
	else
		return (0);
	return (1);
}

long	ft_hexatoi(char *hex)
{
	long	result;
	int		length;

	length = 0;
	result = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	while (hex[length] && length < 8)
		length++;
	while (*hex && length--)
	{
		if (hex_loop(&result, hex))
			hex++;
		else
			break ;
	}
	while (length-- > 0)
	{
		result <<= 8;
		result |= 0xFF;
	}
	return (result);
}

void	swap_pt(t_pt *a, t_pt *b)
{
	t_pt	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
