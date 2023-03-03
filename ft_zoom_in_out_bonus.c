/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_in_out_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:56:30 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 00:18:19 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int keycode, t_data *data)
{
	if (keycode == 69)
	{
		data->zoom += 0.1;
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 78)
	{
		data->zoom -= 0.1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img,
				&data->bits_per_pixel, &data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}
