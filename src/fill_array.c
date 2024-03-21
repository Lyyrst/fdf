/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:35:09 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/08 18:48:51 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fill_line(int **array, char **line, int i)
{
	int			j;
	long int	n;
	int			ret;

	j = 0;
	n = 0;
	ret = 1;
	while (line[j])
	{
		n = ft_atol(line[j]);
		if (n > INT_MAX || n < INT_MIN)
			ret = 0;
		array[i][j] = n;
		j++;
	}
	return (ret);
}

int	fill_array_while(int fd, int **array, char *line, char **a)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	ret = 1;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		line = ft_strtrim(tmp, "\n");
		free(tmp);
		a = ft_split(line, ' ');
		if (!fill_line(array, a, i++))
			ret = 0;
		free(line);
		free_array(a);
	}
	return (ret);
}

int	fill_array(int **array, char *str)
{
	int		fd;
	char	*line;
	char	**a;
	int		ret;

	fd = open(str, O_RDONLY);
	line = 0;
	a = 0;
	ret = fill_array_while(fd, array, line, a);
	close(fd);
	if (ret == 0)
		ft_putstr_fd("a point dont fill in an int\n", 2);
	return (ret);
}
