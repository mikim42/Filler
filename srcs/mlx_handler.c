/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:02:51 by mikim             #+#    #+#             */
/*   Updated: 2017/11/14 23:30:53 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	parse_mlx(t_env *e)
{
	char *line;

	get_next_line(0, &line);
	store_map(e, line);
	free(line);
	e->mlx.win_y = e->map_y * 10 + 50;
	e->mlx.win_x = e->map_x * 10 + 50;
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, e->mlx.win_x, e->mlx.win_y,
	"Filler - 42 Project by. mikim");
	draw_grid(e);
	get_next_line(0, &line);
	store_piece(e, line);
	filler(e);
	free(line);
}

int		loop_hook(t_env *e)
{
	draw_block(e);
	parse_filler(e);
	mlx_do_sync(e->mlx.mlx);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_exit(e, NULL);
	return (0);
}
