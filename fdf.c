/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:33:16 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/22 20:52:59 by aben-nei         ###   ########.fr       */
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

int mouse_hook(int event, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
    if (event == 2)
	{
		data->move_x += 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (event == 1)
	{
		data->move_x -= 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (event == 4)
	{
		data->move_y += 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (event == 5)
	{
		data->move_y -= 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
    return (0);
}

int	key_hook(int keycode, t_data *data)
{
	printf("keycode = %d", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 69) // zoom in
	{
		data->zoom += 0.1;
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 78) // zoom out
	{
		data->zoom -= 0.1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 126 || keycode == 13) // up
	{
		data->move_y -= 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 125 || keycode == 6) // down
	{
		data->move_y += 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 123 || keycode == 0) // left
	{
		data->move_x -= 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 124 || keycode == 2) // right
	{
		data->move_x += 10;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 49) // space and reset
	{
		data->move_x = 0;
		data->move_y = 0;
		data->zoom = 1;
		data->c = 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 15) 
	{
		data->point1.angle_x -= 0.8;
		data->point1.angle_y -= 0.8;
		data->point2.angle_x -= 0.8;
		data->point2.angle_y -= 0.8;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 14) 
	{
		data->point1.angle_x += 0.8;
		data->point1.angle_y += 0.8;
		data->point2.angle_x += 0.8;
		data->point2.angle_y += 0.8;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 5)
	{
		data->point1.x += 1;
		data->point1.y += 1;
		data->point2.x += 1;
		data->point2.y += 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	
	else if (keycode == 17) 
	{
		data->point1.x += 1;
		data->point2.x += 1;
		data->point1.y += 1;
		data->point2.y += 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
	data.point1.angle_x = 0.8;
	data.point1.angle_y = 0.8;
	data.point2.angle_x = 0.8;
	data.point2.angle_y = 0.8;
	data.c = 1;
	ft_check_map_is_valid(av, fd);
	data.tab = map_allocate(av[1], fd);
	fill_map(av[1], fd, data.tab);
	data.height = get_height(av[1], fd);
	data.width = get_width(av[1], fd);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 5120 / 2, 2880 / 2, "");
	data.img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	ft_draw_map(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
