/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:23:25 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 00:20:44 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(t_point *p1, t_point *p2, t_data *data)
{
	int	y1;
	int	y2;
	int	z1;
	int	z2;

	y1 = p1->y;
	y2 = p2->y;
	z1 = p1->z;
	z2 = p2->z;
	p1->x = p1->x;
	p1->y = y1 * cos(data->angle_x) - z1 * sin(data->angle_x);
	p1->z = y1 * sin(data->angle_x) + z1 * cos(data->angle_x);
	p2->x = p2->x;
	p2->y = y2 * cos(data->angle_x) - z2 * sin(data->angle_x);
	p2->z = y2 * sin(data->angle_x) + z2 * cos(data->angle_x);
}

void	rotate_x(t_data *data)
{
	data->angle_x += 0.1;
	data->flag1 = 1;
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	ft_draw_map(data->point1, data->point2, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
