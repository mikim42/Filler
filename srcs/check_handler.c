/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:58:07 by mikim             #+#    #+#             */
/*   Updated: 2017/11/14 10:18:32 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		check_right_wall(t_env *e)
{
	int y;

	y = -1;
	if (ft_strchr(e->map[0], e->player))
		return (1);
	while (e->map[++y])
	{
		if (e->map[y][e->map_x - 1] == e->player)
			return (1);
	}
	return (0);
}

void	check_direction_dr(t_env *e)
{
	if (ft_strchr(e->map[e->map_y - 1], e->player) && check_right_wall(e))
		e->put = FILL_RIGHT;
	else if (e->diff_y > e->diff_x)
	{
		if (ft_strchr(e->map[e->map_y - 1], e->player))
			e->put = RIGHT;
		else
			e->put = DOWN;
	}
	else
	{
		if (check_right_wall(e))
			e->put = DOWN;
		else
			e->put = RIGHT;
	}
}

int		check_left_wall(t_env *e)
{
	int y;

	y = -1;
	if (ft_strchr(e->map[e->map_y - 1], e->player))
		return (1);
	while (e->map[++y])
	{
		if (e->map[y][0] == e->player)
			return (1);
	}
	return (0);
}

void	check_direction_ul(t_env *e)
{
	if (ft_strchr(e->map[0], e->player) && check_left_wall(e))
		e->put = FILL_LEFT;
	else if (e->diff_y > e->diff_x)
	{
		if (ft_strchr(e->map[0], e->player))
			e->put = LEFT;
		else
			e->put = UP;
	}
	else
	{
		if (check_left_wall(e))
			e->put = UP;
		else
			e->put = LEFT;
	}
}

void	check_map(t_env *e)
{
	if (e->pos == DOWN_RIGHT)
	{
		e->diff_y = get_top(e, e->player);
		e->diff_y -= get_bottom(e, e->enemy);
		e->diff_x = get_left(e, e->player);
		e->diff_x -= get_right(e, e->enemy);
		check_direction_ul(e);
	}
	else if (e->pos == UP_LEFT)
	{
		e->diff_y = get_top(e, e->enemy);
		e->diff_y -= get_bottom(e, e->player);
		e->diff_x = get_left(e, e->enemy);
		e->diff_x -= get_right(e, e->player);
		check_direction_dr(e);
	}
}
