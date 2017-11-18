/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:36:37 by mikim             #+#    #+#             */
/*   Updated: 2017/11/14 23:37:17 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	ft_exit(t_env *e, char *msg)
{
	if (e->map)
		ft_splitdel(e->map);
	if (e->piece)
		ft_splitdel(e->piece);
	if (e->mlx.win)
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	if (e->mlx.mlx)
		free(e->mlx.mlx);
	if (msg)
	{
		ft_printf("%s\n", msg);
		exit(-42);
	}
	exit(0);
}

void	filler(t_env *e)
{
	check_map(e);
	if (e->put == UP)
		put_up(e);
	if (e->put == LEFT)
		put_left(e);
	if (e->put == RIGHT)
		put_right(e);
	if (e->put == DOWN)
		put_down(e);
	if (e->put == FILL_LEFT)
		put_fill_left(e);
	if (e->put == FILL_RIGHT)
		put_fill_right(e);
	ft_printf("%d %d\n", e->put_y, e->put_x);
}

void	parse_filler(t_env *e)
{
	char *line;

	if (get_next_line(0, &line) < 1)
		return ;
	if (e->map)
		ft_splitdel(e->map);
	store_map(e, line);
	free(line);
	get_next_line(0, &line);
	if (e->piece)
		ft_splitdel(e->piece);
	store_piece(e, line);
	filler(e);
}

int		main(void)
{
	t_env	e;

	ft_bzero(&e, sizeof(e));
	get_player(&e);
	parse_mlx(&e);
	mlx_do_sync(e.mlx.mlx);
	mlx_hook(e.mlx.win, 2, 2, key_hook, &e);
	mlx_loop_hook(e.mlx.mlx, loop_hook, &e);
	mlx_loop(e.mlx.mlx);
	ft_exit(&e, NULL);
	return (0);
}
