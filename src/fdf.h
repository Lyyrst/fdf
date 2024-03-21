/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:35:26 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 17:37:01 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://macrolibx.kbz8.me/reference/references/ 

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../MacroLibX/includes/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# ifndef WEIGHT
#  define WEIGHT 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_map
{
	int	row;
	int	col;
	int	**a;
}	t_map;

typedef struct s_event
{
	float	scale;
	float	sc;
	int		origin_x;
	int		origin_y;
	int		ratio;
}	t_event;

typedef struct s_coord
{
	int		x_win;
	int		y_win;
	float	x_iso;
	float	y_iso;
}	t_coord;

typedef struct s_draw
{
	int	x0;
	int	y0;
	int	dist_x;
	int	dist_y;
	int	dir_x;
	int	dir_y;
	int	tmp;
	int	tmp2;
}	t_draw;

typedef struct s_main
{
	struct s_mlx	*mlx;
	struct s_map	*map;
	struct s_event	*event;
	struct s_coord	*coord;
	struct s_draw	*draw;
}	t_main;

int			**get_array(char *str, int *row, int *col);
int			fill_array(int **array, char *str);
void		mlx_event(t_main *main, t_mlx *mlx);
void		draw_pts(t_main *main);
void		iso_win(int x, int y, int z, t_main *main);
void		zoom(t_main *main, char c);
void		draw_img(t_main *main);
void		translate(t_main *main, char c);
void		create_img(t_main *main);
void		ratio(t_main *main, int event);
void		draw_first_col(t_main *main, t_draw *draw, t_coord *coord);
void		draw_line(t_main *main, t_draw *draw, int i, int j);
void		draw_first_line(t_main *main, t_draw *draw, int i, int j);
int			get_s_draw(t_main **main);
int			get_s_coord(t_main **main);
int			get_s_event(t_main **main, t_map *map);
int			get_s_map(t_main **main, int row, int col, int **array);
int			get_s_mlx(t_main **main, char *name);
void		free_struct(t_main *main);

#endif
