/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:48:13 by mikim             #+#    #+#             */
/*   Updated: 2017/11/13 23:50:53 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	put_fill_right(t_env *e)
{
	int y;
	int x;

	x = e->map_x;
	while (--x >= 0)
	{
		y = e->map_y;
		while (--y >= 0)
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

void	put_fill_left(t_env *e)
{
	int y;
	int x;

	x = -1;
	while (++x < e->map_x)
	{
		y = -1;
		while (++y < e->map_y)
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
