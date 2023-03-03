/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:54:22 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 18:54:05 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_reset(t_data *data)
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
	data->speed_up = 1.0;
	data->flag_speed = 1;
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	ft_draw_map(data->point2, data->point2, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
