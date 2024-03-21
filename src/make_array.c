/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:24:11 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 16:03:10 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_l(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			i++;
		else if (ft_isdigit(line[i]) == 1)
			i++;
		else if (is_sign(line[i]) == 1 && ft_isdigit(line[i + 1]) == 1)
		{
			if (i == 0)
				i++;
			else if (ft_isdigit(line[i - 1]) == 0)
				i++;
		}
		else
			return (0);
	}
	return (1);
}

static int	read_map(int fd, int *row, int *col)
{
	char	*l;
	int		error;

	l = 0;
	error = 0;
	while (1)
	{
		l = get_next_line(fd);
		if (!l)
		{
			free(l);
			break ;
		}
		if (!check_l(l) || l[0] == '\n' || (*col != 0 && *col != ft_wc(l)))
			error = 1;
		(*row)++;
		*col = ft_wc(l);
		free(l);
	}
	if (error == 1)
	{
		ft_putstr_fd("the map is wrong\n", 2);
		return (0);
	}
	return (1);
}

static int	**allocate_array(int row, int col)
{
	int	**array;
	int	i;

	i = 0;
	array = malloc(sizeof(int *) * row);
	if (!array)
		return (0);
	while (i < row)
	{
		array[i] = malloc(sizeof(int) * col);
		if (!array[i])
		{
			free_int_array(array, i);
			return (0);
		}
		i++;
	}
	return (array);
}

static int	empty_map(int row, int col)
{
	if (row == 0 || col == 0)
	{
		ft_putstr_fd("empty map\n", 2);
		return (0);
	}
	return (1);
}

int	**get_array(char *str, int *row, int *col)
{
	int	fd;
	int	**array;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File not readable or inexistant\n", 2);
		return (0);
	}
	*row = 0;
	*col = 0;
	array = 0;
	if (!read_map(fd, row, col))
	{
		close(fd);
		return (0);
	}
	empty_map(*row, *col);
	array = allocate_array(*row, *col);
	if (!array)
		return (0);
	return (array);
}
