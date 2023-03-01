/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:23:23 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/01 02:00:05 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_width(char *av, int fd)
{
	char	*str;
	int		width;

	fd = open(av, O_RDONLY, 777);
	str = get_next_line(fd);
	width = str_length(str);
	//free(str);
	return (close(fd), width);
}

int	get_height(char *av, int fd)
{
	int		height;
	char	*str;

	fd = open(av, O_RDONLY, 777);
	height = 0;
	str = get_next_line(fd);
	while (str)
	{
		height++;
		str = get_next_line(fd);
	}
	//free(str);
	return (close(fd), height);
}

void get_color(t_data *data, int z1, int z2)
{
	if (z1 != 0 || z2 != 0)
		data->color = 0x0085FF;
	else
		data->color = 0x00FFFFFF;
}

void	drawing_line(t_point p1, t_point p2, t_data *data)
{
	int	i;
	int	z1;
	int	z2;

	z1 = data->tab[p1.y][p1.x];
	z2 = data->tab[p2.y][p2.x];
	if (data->change_color == 1)
		get_color(data, z1, z2);
	z1 = z1*data->c*5;
	z2 = z2*data->c*5;
	p1.x *= 20 * data->zoom;
	p2.x *= 20 * data->zoom;
	p1.y *= 20 * data->zoom;
	p2.y *= 20 * data->zoom;

	if ((data)->flag == 0)
	{
		p1.x = (p1.x - p1.y) * cos(data->point1.angle_x);
		p1.y = (p1.x + p1.y) * cos(data->point1.angle_y) - z1;
		p2.x = (p2.x - p2.y) * cos(data->point2.angle_x);
		p2.y = (p2.x + p2.y) * cos(data->point2.angle_y) - z2;
	}
	p1.x += 5120 / 4 - (20 * data->width / 2) + data->move_x;
	p2.x += 5120 / 4 - (20 * data->width / 2) + data->move_x;
	p1.y += 2880 / 4 - (20 * data->height / 2) + data->move_y;
	p2.y += 2880 / 4 - (20 * data->height / 2) + data->move_y;
	data->x = p1.x;
	data->y = p1.y;
	data->dx = p2.x - p1.x;
	data->dy = p2.y - p1.y;
	if (abs(data->dx) > abs(data->dy))
		data->steps = abs(data->dx);
	else
		data->steps = abs(data->dy);
	data->inc_x = (float)data->dx / (float)data->steps;
	data->inc_y = (float)data->dy / (float)data->steps;
	i = 0;
	while (i < data->steps)
	{
		// mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFFFFFF);
		if(data->x > 0 && data->x < 5120/2 && data->y > 0 && data->y < 2880/2)
			my_mlx_pixel_put(data, data->x, data->y, data->color);
		data->x += data->inc_x;
		data->y += data->inc_y;
		i++;
	}
}

void	ft_draw_map(t_data *data)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->height)
		{
			p1.x = i;
			p1.y = j;
			if (j < data->height - 1)
			{
				p2.x = i;
				p2.y = j + 1;
				drawing_line(p1, p2, data);
			}
			if (i < data->width - 1)
			{
				p2.x = i + 1;
				p2.y = j;
				drawing_line(p1, p2, data);
			}
		}
	}
}
