/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:33:16 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/20 19:24:30 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *av, int fd)
{
	char	*str;
	int		width;

	fd = open(av, O_RDONLY, 777);
	str = get_next_line(fd);
	width = str_length(str);
	return (close(fd), width);
}

int	get_height(char *av, int fd)
{
	int		height;
	char	*str;

	fd = open(av, O_RDONLY, 777);
	height = 0;
	str = get_next_line(fd);
	while (str)
	{
		height++;
		str = get_next_line(fd);
	}
	return (close(fd), height);
}

void	fill_map(char *av, int fd, int **map)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;

	fd = open(av, O_RDONLY, 777);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		j = 0;
		tab = ft_split(str, ' ');
		while (tab[j])
		{
			map[i][j] = ft_atoi(tab[j]);
			j++;
		}
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	**map_allocate(char *av, int fd)
{
	char	*str;
	int **tab;
	int		i;
	int		height_len;
	int		width_len;

	fd = open(av, O_RDONLY, 777);
	i = 0;
	height_len = get_height(av, fd);
	tab = (int **)ft_calloc(sizeof(int *), height_len + 1);
	if (!tab)
		return (0);
	while (i < height_len)
	{
		width_len = get_width(av, fd);
		tab[i] = (int *)ft_calloc(sizeof(int), width_len + 1);
		if (!tab[i])
			return (0);
		i++;
	}
	return (close(fd), tab);
}

int	main(int ac, char **av)
{
	//int	**tab;
	int	fd;
	t_data	data;

	if (ac != 2)
		return (ft_putendl_fd("Usage: ./fdf <filename>", 1), exit(1), 0);
	fd = open(av[1], O_RDONLY, 777);
	ft_check_map_is_valid(av, fd);
	data.tab = map_allocate(av[1], fd);
	fill_map(av[1], fd, data.tab);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1500, 500, "drawing line");
	ft_draw_map(&data, get_height(av[1], fd), get_width(av[1], fd));
	mlx_loop(data.mlx);
	return (0);
}
