/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:23:25 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/02 08:29:47 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_rotate_x(t_point *p1, t_point *p2, t_data *data)
{
	int y1;
	int y2;
	// int x1;
	// int x2;
	int z1;
	int z2;

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