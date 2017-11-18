/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:49:26 by mikim             #+#    #+#             */
/*   Updated: 2017/11/14 23:32:08 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	draw_cell(t_env *e, int y, int x, int color)
{
	int i;
	int j;

	i = 0;
	while (++i < 10)
	{
		j = 0;
		while (++j < 10)
			mlx_pixel_put(e->mlx.mlx, e->mlx.win,
			25 + (x * 10) + j, 25 + (y * 10) + i, color);
	}
}

void	draw_block(t_env *e)
{
	int y;
	int x;

	y = -1;
	while (e->map[++y])
	{
		x = -1;
		while (e->map[y][++x])
			if (ENEMY(y, x))
				draw_cell(e, y, x, 0xFF0000);
			else if (PLAYER(y, x))
				draw_cell(e, y, x, 0x33CC33);
	}
}

void	draw_start(t_env *e)
{
	int y;
	int x;

	y = -1;
	while (e->map[++y])
	{
		x = -1;
		while (e->map[y][++x])
		{
			if (ENEMY(y, x))
				draw_cell(e, y, x, 0xFF0000);
			else if (PLAYER(y, x))
				draw_cell(e, y, x, 0x33CC33);
		}
	}
}

void	draw_grid(t_env *e)
{
	int y;
	int x;

	y = 25;
	while (y < e->mlx.win_y - 24)
	{
		x = 24;
		while (++x < e->mlx.win_x - 24)
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y, 0xFFFFFF);
		y += 10;
	}
	x = 25;
	while (x < e->mlx.win_x - 24)
	{
		y = 24;
		while (++y < e->mlx.win_y - 24)
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y, 0xFFFFFF);
		x += 10;
	}
	draw_start(e);
}
