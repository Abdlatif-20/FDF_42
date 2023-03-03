/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:47:27 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 00:25:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate1(int keycode, t_data *data)
{
	if (keycode == 123 || keycode == 0)
	{
		data->move_x -= 10 * data->change_speed;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 124 || keycode == 2)
	{
		printf("%f\n", data->change_speed);
		data->move_x += 10 * data->change_speed;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}

void	ft_translate(int keycode, t_data *data)
{
	if (keycode == 126 || keycode == 13)
	{
		data->move_y -= 10 * data->change_speed;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 125 || keycode == 6)
	{
		data->move_y += 10 * data->change_speed;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	ft_translate1(keycode, data);
}
