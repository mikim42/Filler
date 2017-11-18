/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:49:49 by mikim             #+#    #+#             */
/*   Updated: 2017/11/13 21:03:10 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		get_bottom(t_env *e, char c)
{
	int y;
	int x;

	y = e->map_y;
	while (--y >= 0)
	{
		x = e->map_x;
		while (--x >= 0)
			if (e->map[y][x] == c || e->map[y][x] == c + 32)
				return (y);
	}
	return (0);
}

int		get_right(t_env *e, char c)
{
	int right;
	int y;
	int x;

	y = -1;
	right = -1;
	while (e->map[++y])
	{
		x = -1;
		while (e->map[y][++x])
			if ((e->map[y][x] == c || e->map[y][x] == c + 32) &&
				right < x)
				right = x;
	}
	return (right);
}

int		get_left(t_env *e, char c)
{
	int left;
	int y;
	int x;

	y = -1;
	left = e->map_x + 1;
	while (e->map[++y])
	{
		x = -1;
		while (e->map[y][++x])
			if ((e->map[y][x] == c || e->map[y][x] == c + 32) &&
				left > x)
				left = x;
	}
	return (left);
}

int		get_top(t_env *e, char c)
{
	int y;
	int x;

	y = -1;
	while (e->map[++y])
	{
		x = -1;
		while (e->map[y][++x])
			if (e->map[y][x] == c || e->map[y][x] == c + 32)
				return (y);
	}
	return (0);
}
