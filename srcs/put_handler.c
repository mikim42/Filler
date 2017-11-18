/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:52:27 by mikim             #+#    #+#             */
/*   Updated: 2017/11/14 10:12:37 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		check_valid(t_env *e, int y, int x)
{
	int i;
	int j;
	int	cnt;

	i = -1;
	cnt = 0;
	while (e->piece[++i])
	{
		j = -1;
		while (e->piece[i][++j])
		{
			if (e->piece[i][j] == '*' &&
				(OUT(y + i, x + j) || ENEMY(y + i, x + j)))
				return (0);
			if (e->piece[i][j] == '*' && PLAYER(y + i, x + j))
				cnt++;
		}
	}
	return (cnt == 1 ? 1 : 0);
}

void	put_down(t_env *e)
{
	int y;
	int x;

	y = e->map_y;
	while (--y >= 0)
	{
		x = e->map_x;
		while (--x >= 0)
		{
			if (check_valid(e, y, x))
			{
				e->put_y = y;
				e->put_x = x;
				return ;
			}
		}
	}
}

void	put_right(t_env *e)
{
	int y;
	int x;

	y = -e->piece_y;
	while (++y < e->map_y)
	{
		x = e->map_x;
		while (--x >= 0)
		{
			if (check_valid(e, y, x))
			{
				e->put_y = y;
				e->put_x = x;
				return ;
			}
		}
	}
}

void	put_left(t_env *e)
{
	int y;
	int x;

	y = e->map_y;
	while (--y >= 0)
	{
		x = -e->piece_x;
		while (++x < e->map_x)
		{
			if (check_valid(e, y, x))
			{
				e->put_y = y;
				e->put_x = x;
				return ;
			}
		}
	}
}

void	put_up(t_env *e)
{
	int y;
	int x;

	y = -e->piece_y;
	while (++y < e->map_y)
	{
		x = -e->piece_x;
		while (++x < e->map_x)
		{
			if (check_valid(e, y, x))
			{
				e->put_y = y;
				e->put_x = x;
				return ;
			}
		}
	}
}
