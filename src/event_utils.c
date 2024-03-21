/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:32:44 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 17:35:46 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_main *main, char c)
{
	if (c == '1')
		main->event->sc += 0.5;
	if (c == '0')
	{
		if (main->event->sc >= 0.6)
			main->event->sc -= 0.5;
	}
	mlx_destroy_image(main->mlx->mlx, main->mlx->img);
	create_img(main);
}

void	translate(t_main *main, char c)
{
	t_event	*event;

	event = main->event;
	if (c == 'r')
		event->origin_x -= 20;
	if (c == 'l')
		event->origin_x += 20;
	if (c == 'u')
		event->origin_y -= 20;
	if (c == 'd')
		event->origin_y += 20;
	mlx_destroy_image(main->mlx->mlx, main->mlx->img);
	create_img(main);
}

void	ratio(t_main *main, int event)
{
	if (event == 89)
		main->event->ratio = 1;
	if (event == 90)
		main->event->ratio = 3;
	if (event == 91)
		main->event->ratio = 4;
	if (event == 92)
		main->event->ratio = 5;
	if (event == 93)
		main->event->ratio = 6;
	if (event == 94)
		main->event->ratio = 7;
	if (event == 95)
		main->event->ratio = 8;
	if (event == 96)
		main->event->ratio = 9;
	if (event == 97)
		main->event->ratio = 20;
	mlx_destroy_image(main->mlx->mlx, main->mlx->img);
	create_img(main);
}
