/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:23:23 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/21 19:22:40 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	drawing_line(t_point p1, t_point p2, t_data *data)
{
	int	dx;
	int	dy;
	int	i;
	int	z1;
	int	z2;

	z1 = data->tab[p1.y][p1.x];
	z2 = data->tab[p2.y][p2.x];
	p1.x *= 15 * data->zoom;
	p2.x *= 15 * data->zoom;
	p1.y *= 15 * data->zoom;
	p2.y *= 15 * data->zoom;
	p1.x = (p1.x - p1.y) * cos(0.8);
	p1.y = (p1.x + p1.y) * cos(0.8) - z1;
	p2.x = (p2.x - p2.y) * cos(0.8);
	p2.y = (p2.x + p2.y) * cos(0.8) - z2;
	p1.x += 5120 / 4 - (15 * data->width / 2) + data->move_x;
	p2.x += 5120 / 4 - (15 * data->width / 2) + data->move_x;
	p1.y += 2880 / 4 - (15 * data->height / 2) + data->move_y;
	p2.y += 2880 / 4 - (15 * data->height / 2) + data->move_y;
	data->x = p1.x;
	data->y = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs(dx) > abs(dy))
		data->steps = abs(dx);
	else
		data->steps = abs(dy);
	data->inc_x = (float)dx / (float)data->steps;
	data->inc_y = (float)dy / (float)data->steps;
	i = 0;
	while (i < data->steps)
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFFFFFF);
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
