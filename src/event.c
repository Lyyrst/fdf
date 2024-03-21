/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:25:59 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/02/24 18:17:03 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	key_hook(int event, void *param)
{
	t_main	*main;

	main = param;
	if (event == 41)
		mlx_loop_end(main->mlx->mlx);
	if (event == 79)
		translate(main, 'r');
	if (event == 80)
		translate(main, 'l');
	if (event == 81)
		translate(main, 'u');
	if (event == 82)
		translate(main, 'd');
	if (event >= 89 && event <= 97)
		ratio(main, event);
	return (0);
}

int	wheel_hook(int event, void *param)
{
	t_main	*main;

	main = param;
	if (event == 1)
		zoom(main, '1');
	if (event == 2)
		zoom(main, '0');
	return (0);
}

void	mlx_event(t_main *main, t_mlx *mlx)
{
	void	*p_mlx;
	void	*p_main;

	p_mlx = mlx;
	p_main = main;
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, win_hook, p_mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, p_main);
	mlx_on_event(mlx->mlx, mlx->win, MLX_MOUSEWHEEL, wheel_hook, p_main);
}
