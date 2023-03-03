/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:57:57 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 00:15:03 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_color(t_data *data, int z1, int z2)
{
	if (z1 != 0 || z2 != 0)
		data->color = 0x0085FF;
	else
		data->color = 0x00FFFFFF;
}

void	drawing_line1(t_point p1, t_point p2, t_data *data)
{
	if (data->flag1 == 1)
		ft_rotate_x(&p1, &p2, data);
	if (data->flag2 == 1)
		ft_rotate_y(&p1, &p2, data);
	if (data->flag == 0)
	{
		p1.x = (p1.x - p1.y) * cos(0.72);
		p1.y = (p1.x + p1.y) * cos(0.72) - p1.z;
		p2.x = (p2.x - p2.y) * cos(0.72);
		p2.y = (p2.x + p2.y) * cos(0.72) - p2.z;
	}
	p1.x += 5120 / 4 - (15 * data->width / 2) + data->move_x;
	p2.x += 5120 / 4 - (15 * data->width / 2) + data->move_x;
	p1.y += 2880 / 4 - (15 * data->height / 2) + data->move_y;
	p2.y += 2880 / 4 - (15 * data->height / 2) + data->move_y;
	data->x = p1.x;
	data->y = p1.y;
	data->dx = p2.x - p1.x;
	data->dy = p2.y - p1.y;
	if (abs(data->dx) > abs(data->dy))
		data->steps = abs(data->dx);
	else
		data->steps = abs(data->dy);
}

void	drawing_line(t_point p1, t_point p2, t_data *data)
{
	int	i;

	p1.z = data->tab[p1.y][p1.x];
	p2.z = data->tab[p2.y][p2.x];
	if (data->change_color == 1)
		get_color(data, p1.z, p2.z);
	p1.z = p1.z * data->c * 5;
	p2.z = p2.z * data->c * 5;
	p1.x *= 15 * data->zoom;
	p2.x *= 15 * data->zoom;
	p1.y *= 15 * data->zoom;
	p2.y *= 15 * data->zoom;
	drawing_line1(p1, p2, data);
	data->inc_x = (float)data->dx / (float)data->steps;
	data->inc_y = (float)data->dy / (float)data->steps;
	i = 0;
	while (i < data->steps)
	{
		if (data->x > 0 && data->x < 5120 / 2
			&& data->y > 0 && data->y < 2880 / 2)
			my_mlx_pixel_put(data, data->x, data->y, data->color);
		data->x += data->inc_x;
		data->y += data->inc_y;
		i++;
	}
}
