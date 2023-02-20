/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:23:23 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/20 19:22:00 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing_line(int X1, int Y1, int X2, int Y2, t_data *data)
{
	int		dx;
	int		dy;
	int		i;
	int		z1=0;
	int		z2=0;
	int		steps;
	float	inc_x, x;
	float	inc_y, y;

	X1 = X1*30;
	X2 = X2*30;
	Y1 = Y1*30;
	Y2 = Y2*30;

	z1 = data->tab[X1][Y1];
	z2 = data->tab[X2][Y2];

	X1 = (X1 - Y1) * cos (0.52);
	Y1 = (X1 + Y1) * cos(0.52) - z1;

	X2 = (X2 - Y2) * cos (0.52);
	Y2 = (X2 + Y2) * cos(0.52) - z2;

	x = X1;
	y = Y1;
	dx = X2 - X1;
	dy = Y2 - Y1;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	inc_x = (float)dx / (float)steps;
	inc_y = (float)dy / (float)steps;
	i = 0;
	while (i < steps)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
		x += inc_x;
		y += inc_y;
		i++;
	}
}

void	ft_draw_map(t_data *data, int hight, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < hight)
		{
			if (j < hight - 1)
				drawing_line(i, j, i, j + 1, data);
			if (i < width - 1)
				drawing_line(i, j, i + 1, j, data);
			j++;
		}
		i++;
	}
}
