/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:30:17 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/07 16:48:08 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(int x, int y, int z, t_main *main)
{
	float	n;

	n = M_PI / main->event->ratio;
	main->coord->x_iso = (x - y) * cos(n) * main->event->scale;
	main->coord->y_iso = -z + (x + y) * sin(n) * main->event->scale;
}

void	iso_win(int x, int y, int z, t_main *main)
{
	t_coord	*coord;
	t_event	*event;

	coord = main->coord;
	event = main->event;
	isometric(x, y, z, main);
	coord->x_win = (int)(coord->x_iso * event->sc + event->origin_x);
	coord->y_win = (int)(coord->y_iso * event->sc + event->origin_y);
}

void	draw_img(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	draw_first_col(main, main->draw, main->coord);
	while (i < main->map->row)
	{
		j = 1;
		while (j < main->map->col)
		{
			if (i == 0)
				draw_first_line(main, main->draw, i, j);
			else
				draw_line(main, main->draw, i, j);
			j++;
		}
		i++;
	}
}

void	create_img(t_main *main)
{
	t_mlx	*mlx;

	mlx = main->mlx;
	mlx->img = mlx_new_image(mlx->mlx, WEIGHT, HEIGHT);
	draw_img(main);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	free_struct(t_main *main)
{
	if (main)
	{
		if (main->coord)
			free(main->coord);
		if (main->draw)
			free(main->draw);
		if (main->event)
			free(main->event);
		if (main->map)
			free(main->map);
		if (main->mlx)
			free(main->mlx);
		free(main);
	}
}
