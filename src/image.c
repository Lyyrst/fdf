/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:18:05 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 17:34:33 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initiate_value(t_draw *draw, int x1, int y1)
{
	draw->dist_x = labs(x1 - draw->x0);
	draw->dist_y = labs(y1 - draw->y0);
	draw->dir_x = -1;
	draw->dir_y = -1;
	if (draw->x0 < x1)
		draw->dir_x = 1;
	if (draw->y0 < y1)
		draw->dir_y = 1;
	draw->tmp = draw->dist_y / 2;
	if (draw->dist_x > draw->dist_y)
		draw->tmp = draw->dist_x / 2;
}

static void	draw_segment(t_mlx *mlx, t_draw *draw, int x1, int y1)
{
	initiate_value(draw, x1, y1);
	while (1)
	{
		if (draw->x0 >= 1920 || draw->y0 >= 1080
			|| draw->x0 < 0 || draw->y0 < 0)
			break ;
		mlx_set_image_pixel(mlx->mlx, mlx->img, draw->x0, draw->y0, 0xFFFFFFFF);
		if ((draw->x0 == x1 && draw->y0 == y1)
			|| (draw->dir_x == 1 && draw->x0 > x1)
			|| (draw->dir_x == -1 && draw->x0 < x1)
			|| (draw->dir_y == 1 && draw->y0 > y1)
			|| (draw->dir_y == -1 && draw->y0 < y1))
			break ;
		draw->tmp2 = draw->tmp;
		if (draw->tmp2 > -draw->dist_x)
		{
			draw->tmp -= draw->dist_y;
			draw->x0 += draw->dir_x;
		}
		if (draw->tmp2 < draw->dist_y)
		{
			draw->tmp += draw->dist_x;
			draw->y0 += draw->dir_y;
		}
	}
}

void	draw_first_line(t_main *main, t_draw *draw, int i, int j)
{
	iso_win(j - 1, i, main->map->a[i][j - 1], main);
	draw->x0 = main->coord->x_win;
	draw->y0 = main->coord->y_win;
	iso_win(j, i, main->map->a[i][j], main);
	draw_segment(main->mlx, draw, main->coord->x_win, main->coord->y_win);
}

void	draw_line(t_main *main, t_draw *draw, int i, int j)
{
	iso_win(j - 1, i, main->map->a[i][j - 1], main);
	draw->x0 = main->coord->x_win;
	draw->y0 = main->coord->y_win;
	iso_win(j, i, main->map->a[i][j], main);
	draw_segment(main->mlx, draw, main->coord->x_win, main->coord->y_win);
	iso_win(j, i - 1, main->map->a[i - 1][j], main);
	draw->x0 = main->coord->x_win;
	draw->y0 = main->coord->y_win;
	iso_win(j, i, main->map->a[i][j], main);
	draw_segment(main->mlx, draw, main->coord->x_win, main->coord->y_win);
}

void	draw_first_col(t_main *main, t_draw *draw, t_coord *coord)
{
	int	i;

	i = 1;
	iso_win(0, 0, main->map->a[0][0], main);
	mlx_set_image_pixel(main->mlx->mlx, main->mlx->img,
		coord->x_win, coord->y_win, 0xFFFFFFFF);
	while (i < main->map->row)
	{
		iso_win(0, i - 1, main->map->a[i - 1][0], main);
		draw->x0 = main->coord->x_win;
		draw->y0 = main->coord->y_win;
		iso_win(0, i, main->map->a[i][0], main);
		draw_segment(main->mlx, draw, coord->x_win, coord->y_win);
		i++;
	}
}
