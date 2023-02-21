/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:33:16 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/21 19:48:04 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	//free(str);
	close(fd);
}

int	**map_allocate(char *av, int fd)
{
	int		**tab;
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

int	key_hook(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		data->zoom += 0.1;
		mlx_clear_window(data->mlx, data->win);
		ft_draw_map(data);
	}
	if (keycode == 78)
	{
		data->zoom -= 0.1;
		mlx_clear_window(data->mlx, data->win);
		ft_draw_map(data);
	}
	if (keycode == 126)
	{
		data->move_y -= 10;
		mlx_clear_window(data->mlx, data->win);
		ft_draw_map(data);
	}
	if (keycode == 125)
	{
		data->move_y += 10;
		mlx_clear_window(data->mlx, data->win);
		ft_draw_map(data);
	}
	if (keycode == 123)
	{
		data->move_x -= 10;
		mlx_clear_window(data->mlx, data->win);
		ft_draw_map(data);
	}
	if (keycode == 124)
	{
		data->move_x += 10;
		mlx_clear_window(data->mlx, data->win);
		ft_draw_map(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2)
		return (ft_putendl_fd("Usage: ./fdf <filename>", 1), exit(1), 0);
	fd = 0;
	data.zoom = 1;
	data.move_x = 0;
	data.move_y = 0;
	ft_check_map_is_valid(av, fd);
	data.tab = map_allocate(av[1], fd);
	fill_map(av[1], fd, data.tab);
	data.height = get_height(av[1], fd);
	data.width = get_width(av[1], fd);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 5120 / 2, 2880 / 2, "");
	ft_draw_map(&data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
