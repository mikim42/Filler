/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:54:35 by mikim             #+#    #+#             */
/*   Updated: 2017/11/14 10:07:12 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	store_piece(t_env *e, char *info)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_strsplit(info, ' ');
	e->piece_y = ft_atoi(split[1]);
	e->piece_x = ft_atoi(split[2]);
	e->piece = ft_memalloc(sizeof(char*) * (e->piece_y + 1));
	while (++i < e->piece_y)
	{
		if (get_next_line(0, &e->piece[i]) < 1)
			ft_exit(e, "ERROR");
	}
	ft_splitdel(split);
}

int		get_start_pos(t_env *e)
{
	int y;
	int x;

	y = -1;
	while (e->map[++y])
	{
		x = -1;
		while (e->map[y][++x])
		{
			if (e->map[y][x] == e->player)
				return (UP_LEFT);
			if (e->map[y][x] == e->enemy)
				return (DOWN_RIGHT);
		}
	}
	return (0);
}

void	store_map(t_env *e, char *info)
{
	char	**split;
	char	*line;
	int		i;

	split = ft_strsplit(info, ' ');
	e->map_y = ft_atoi(split[1]);
	e->map_x = ft_atoi(split[2]);
	e->map = ft_memalloc(sizeof(char*) * (e->map_y + 1));
	ft_splitdel(split);
	get_next_line(0, &line);
	free(line);
	i = -1;
	while (++i < e->map_y)
	{
		get_next_line(0, &line);
		e->map[i] = ft_strdup(line + 4);
		free(line);
	}
	e->pos == 0 ? e->pos = get_start_pos(e) : 0;
}

void	get_player(t_env *e)
{
	char *line;

	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
	{
		e->player = 'O';
		e->enemy = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		e->player = 'X';
		e->enemy = 'O';
	}
	free(line);
}
