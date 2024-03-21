/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:33:15 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 17:36:01 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_s_mlx(t_main **main, char *name)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WEIGHT, HEIGHT, name);
	mlx->img = 0;
	(*main)->mlx = mlx;
	return (1);
}

int	get_s_map(t_main **main, int row, int col, int **array)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->a = array;
	map->col = col;
	map->row = row;
	(*main)->map = map;
	return (1);
}

int	get_s_event(t_main **main, t_map *map)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	(void)map;
	if (!event)
		return (0);
	if ((*main)->map->col > 100 || (*main)->map->row > 100)
		event->scale = 5.0;
	else
		event->scale = 3.0;
	event->origin_x = WEIGHT / 2;
	event->origin_y = HEIGHT / 10;
	if ((fmin(WEIGHT / (map->col * 10), HEIGHT / (map->row * 10)) > 0.0))
		event->sc = fmin(WEIGHT / (map->col * 10), HEIGHT / (map->row * 10));
	else
		event->sc = 0.5;
	event->ratio = 5;
	(*main)->event = event;
	return (1);
}

int	get_s_coord(t_main **main)
{
	t_coord	*coord;

	coord = malloc(sizeof(t_coord));
	if (!coord)
		return (0);
	(*main)->coord = coord;
	return (1);
}

int	get_s_draw(t_main **main)
{
	t_draw	*draw;

	draw = malloc(sizeof(t_draw));
	if (!draw)
		return (0);
	(*main)->draw = draw;
	return (1);
}
