/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_y_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:31:00 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 19:08:25 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_rotate_y(t_point *p1, t_point *p2, t_data *data)
{
	int	y[2];
	int	x[2];
	int	z[2];

	y[0] = p1->y;
	y[1] = p2->y;
	z[0] = p1->z;
	z[1] = p2->z;
	x[0] = p1->x;
	x[1] = p2->x;
	p1->x = x[0] * cos(data->angle_y * data->speed_up) + z[0] * sin(data->angle_y * data->speed_up);
	p1->y = y[0];
	p1->z = -x[0] * sin(data->angle_y * data->speed_up) + z[0] * cos(data->angle_y * data->speed_up);
	p2->x = x[1] * cos(data->angle_y * data->speed_up) + z[1] * sin(data->angle_y * data->speed_up);
	p2->y = y[1];
	p2->z = -x[1] * sin(data->angle_y * data->speed_up) + z[1] * cos(data->angle_y * data->speed_up);
}

void	rotate_y(t_data *data)
{
	data->angle_y += 0.1;
	data->flag2 = 1;
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	ft_draw_map(data->point2, data->point2, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
