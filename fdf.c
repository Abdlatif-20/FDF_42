/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:33:16 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/02 02:22:16 by aben-nei         ###   ########.fr       */
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

int	**map_allocate(char *av, int fd, t_data *data)
{
	int		**tab;
	int		i;

	fd = open(av, O_RDONLY, 777);
	i = 0;
	tab = (int **)ft_calloc(sizeof(int *), data->height + 1);
	if (!tab)
		return (0);
	while (i <  data->height )
	{
		tab[i] = (int *)ft_calloc(sizeof(int), data->width + 1);
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
	printf("keycode = %d\n", keycode);
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
		data->color = 16777215;
		data->flag = 0;
		data->flag1 = 0;
		data->flag2 = 0;
		data->angle_x = 0;
		data->angle_y = 0;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	/*------------ rotate------------------*/
	else if (keycode == 15) // rotate over x | up/down = r
	{
		data->angle_x += 0.1;
		data->flag1 = 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 14) // rotate over y | left/right = e
	{
		data->angle_y += 0.1;
		data->flag2 = 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (keycode == 3)
	{
		if(data->change_color == 0)
			data->change_color = 1;
		else
			data->change_color = 0;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (keycode == 5) // z-->zoom in = g
	{
		data->c += 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (keycode == 4) // z-->zoom out = h
	{
		data->c -= 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	
	if (keycode == 38) 
	{
		data->flag = 1;
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
	(void)av;

	if (ac != 2)
		return (ft_putendl_fd("Usage: ./fdf <filename>", 1), exit(1), 0);
	fd = 0;
	data.zoom = 1;
	data.move_x = 0;
	data.move_y = 0;
	data.color = 16777215;
	data.c = 1;
	data.change_color = 0;
	data.flag = 0;
	data.flag1 = 0;
	data.flag2 = 0;
	data.angle_x = 0;
	data.angle_y = 0;
	get_width_height(av[1], fd, &data);
	printf("width = %d\n", data.width);
	printf("height = %d\n", data.height);
	ft_check_map_is_valid(av, fd);
	data.tab = map_allocate(av[1], fd, &data);
	fill_map(av[1], fd, data.tab);
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
