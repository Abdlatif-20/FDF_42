/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:23:23 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/08 19:30:04 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../Bonus/fdf_bonus.h"

void	fill_map(char *av, int fd, int **map)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;

	fd = open(av, O_RDONLY, 777);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		j = 0;
		tab = ft_split(str, ' ');
		while (tab[j])
		{
			map[i][j] = ft_atoi(tab[j]);
			j++;
		}
		free_tab(tab);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i++]);
	}
	free (tab);
}

int	ft_close(void)
{
	exit(0);
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
