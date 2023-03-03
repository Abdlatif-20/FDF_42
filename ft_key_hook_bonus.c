/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:29:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 00:17:19 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook2(t_data *data)
{
	data->flag = 1;
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	ft_draw_map(data->point2, data->point2, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	key_hook1(int keycode, t_data *data)
{
	if (keycode == 5)
	{
		data->c += 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 4)
	{
		data->c -= 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}

int	key_hook(int keycode, t_data *data)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 1)
		data->change_speed += 1.5;
	if ((keycode >= 123 && keycode <= 126) || keycode == 0
		|| keycode == 2 || keycode == 6 || keycode == 13)
		ft_translate(keycode, data);
	else if (keycode == 69 || keycode == 78)
		ft_zoom(keycode, data);
	else if (keycode == 49)
		ft_reset(data);
	else if (keycode == 15)
		rotate_x(data);
	else if (keycode == 14)
		rotate_y(data);
	else if (keycode == 3)
		ft_color(data);
	else if (keycode == 5 || keycode == 4)
		key_hook1(keycode, data);
	else if (keycode == 38)
		key_hook2(data);
	return (0);
}
