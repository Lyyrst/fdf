/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:39:23 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/07 15:47:44 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(t_main *main)
{
	ft_putstr_fd("program error\n", 2);
	free_struct(main);
	exit(EXIT_FAILURE);
}

static void	fdf(t_main *main)
{
	create_img(main);
	mlx_event(main, main->mlx);
	mlx_loop(main->mlx->mlx);
	mlx_destroy_window(main->mlx->mlx, main->mlx->win);
	mlx_destroy_image(main->mlx->mlx, main->mlx->img);
	mlx_destroy_display(main->mlx->mlx);
}

static t_main	*get_struct(int row, int col, char *name, int **array)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	if (!main)
		error(main);
	if (!get_s_mlx(&main, name))
		error(main);
	if (!get_s_map(&main, row, col, array))
		error(main);
	if (!get_s_coord(&main))
		error(main);
	if (!get_s_event(&main, main->map))
		error(main);
	if (!get_s_draw(&main))
		error(main);
	return (main);
}

int	main(int argc, char **argv)
{
	int		**array;
	int		row;
	int		col;
	t_main	*main;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong size of arguments\n", 2);
		return (0);
	}
	array = get_array(argv[1], &row, &col);
	if (!array)
		return (0);
	if (!fill_array(array, argv[1]))
	{
		free_int_array(array, row);
		return (0);
	}
	main = get_struct(row, col, argv[1], array);
	fdf(main);
	free_int_array(array, row);
	free_struct(main);
	return (0);
}
