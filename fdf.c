/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:33:16 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 00:33:47 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initialized(t_data *data)
{
	data->zoom = 1;
	data->move_x = 0;
	data->move_y = 0;
	data->color = 16777215;
	data->c = 1;
	data->change_color = 0;
	data->flag = 0;
	data->flag1 = 0;
	data->flag2 = 0;
	data->angle_x = 0;
	data->angle_y = 0;
	data->change_speed = 1.0;
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
	free(str);
	close(fd);
}

int	**map_allocate(char *av, int fd, t_data *data)
{
	int		**tab;
	int		i;

	fd = open(av, O_RDONLY, 777);
	i = 0;
	tab = (int **)ft_calloc(sizeof(int *), data->height + 1);
	if (!tab)
		return (0);
	while (i < data->height)
	{
		tab[i] = (int *)ft_calloc(sizeof(int), data->width + 1);
		if (!tab[i])
			return (0);
		i++;
	}
	return (close(fd), tab);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	(void)av;
	if (ac != 2)
		return (ft_putendl_fd("Usage: ./fdf <filename>", 1), exit(1), 0);
	fd = 0;
	ft_check_map_is_valid(av, fd);
	ft_initialized(&data);
	get_width_height(av[1], fd, &data);
	printf("width = %d\n", data.width);
	printf("height = %d\n", data.height);
	data.tab = map_allocate(av[1], fd, &data);
	fill_map(av[1], fd, data.tab);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 5120 / 2, 2880 / 2, "fdf");
	data.img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	ft_draw_map(data.point1, data.point1, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
