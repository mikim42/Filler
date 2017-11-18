/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:34:08 by mikim             #+#    #+#             */
/*   Updated: 2017/11/14 23:07:42 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <mlx.h>

# define UP_LEFT 1
# define DOWN_RIGHT 2
# define UP 1
# define LEFT 2
# define RIGHT 3
# define DOWN 4
# define FILL_LEFT 5
# define FILL_RIGHT 6

# define OUT(y, x) ((y >= e->map_y || x >= e->map_x) || (y < 0 || x < 0))
# define ENEMY(y, x) (e->map[y][x] == e->enemy || e->map[y][x] == e->enemy + 32)
# define PLAYER(y, x) (e->map[y][x] == e->player)

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			win_y;
	int			win_x;
}				t_mlx;

typedef struct	s_env
{
	char		player;
	char		enemy;
	int			pos;
	char		**map;
	int			map_y;
	int			map_x;
	char		**piece;
	int			piece_y;
	int			piece_x;
	int			diff_y;
	int			diff_x;
	int			put;
	int			put_y;
	int			put_x;
	t_mlx		mlx;
}				t_env;

/*
**				main
*/
void			parse_filler(t_env *e);
void			filler(t_env *e);
void			ft_exit(t_env *e, char *msg);

/*
**				parse_handler
*/
void			get_player(t_env *e);
void			store_map(t_env *e, char *info);
int				get_start_pos(t_env *e);
void			store_piece(t_env *e, char *info);

/*
**				check_handler
*/
void			check_map(t_env *e);
void			check_direction_ul(t_env *e);
int				check_left_wall(t_env *e);
void			check_direction_dr(t_env *e);
int				check_right_wall(t_env *e);

/*
**				diff_handler
*/
int				get_top(t_env *e, char c);
int				get_left(t_env *e, char c);
int				get_right(t_env *e, char c);
int				get_bottom(t_env *e, char c);

/*
**				put_handler
*/
void			put_up(t_env *e);
void			put_left(t_env *e);
void			put_right(t_env *e);
void			put_down(t_env *e);
void			put_fill_right(t_env *e);
void			put_fill_left(t_env *e);
int				check_valid(t_env *e, int y, int x);

/*
**				mlx_handler
*/
void			parse_mlx(t_env *e);
int				key_hook(int keycode, t_env *e);
int				loop_hook(t_env *e);

/*
**				draw_handler
*/
void			draw_grid(t_env *e);
void			draw_block(t_env *e);
void			draw_cell(t_env *e, int y, int x, int color);

#endif
