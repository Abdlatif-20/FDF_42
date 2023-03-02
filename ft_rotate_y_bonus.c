/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_y_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:31:00 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/02 08:32:13 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_rotate_y(t_point *p1, t_point *p2, t_data *data)
{
    int y1;
	int y2;
	int x1;
	int x2;
	int z1;
	int z2;
    
        y1 = p1->y;
		y2 = p2->y;
		z1 = p1->z;
		z2 = p2->z;
		x1 = p1->x;
		x2 = p2->x;
		p1->x = x1 * cos(data->angle_y) + z1 * sin(data->angle_y);
		p1->y = y1;
		p1->z = -x1 * sin(data->angle_y) + z1 * cos(data->angle_y);
		p2->x = x2 * cos(data->angle_y) + z2 * sin(data->angle_y);
		p2->y = y2;
		p2->z = -x2 * sin(data->angle_y) + z2 * cos(data->angle_y);
}