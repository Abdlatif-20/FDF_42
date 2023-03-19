/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:54:22 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/19 18:21:02 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_reset(t_data *data)
{
	data->zoom = 1;
	data->move_x = 0;
	data->move_y = 0;
	data->color = 16777215;
	data->zoom_z = 1;
	data->change_color = 0;
	data->flag_projection = 0;
	data->flag_x = 0;
	data->flag_y = 0;
	data->angle_x = 0;
	data->angle_y = 0;
	data->speed_up = 1.0;
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 5120 / 2, 2880 / 2);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	ft_draw_map(data->point2, data->point2, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
