/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:23:23 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/03 19:13:46 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../Bonus/fdf_bonus.h"

int	ft_close(void)
{
	exit(0);
}

void	get_width_height(char *av, int fd, t_data *data)
{
	char	*str;
	int		height;

	fd = open(av, O_RDONLY, 777);
	str = get_next_line(fd);
	data->width = str_length(str);
	height = 0;
	while (str)
	{
		height++;
		str = get_next_line(fd);
		free(str);
	}
	free(str);
	data->height = height;
}

void	ft_draw_map(t_point p1, t_point p2, t_data *data)
{
	int		i;
	int		j;

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
