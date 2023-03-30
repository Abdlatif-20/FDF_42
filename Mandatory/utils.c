/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:23:23 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/24 17:12:30 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_keycode_event(int keycode)
{
	ft_putstr_fd("keycode - event = ", 1);
	ft_putnbr(keycode);
	ft_putchar_fd('\n', 1);
}

int	**map_allocate(t_data *data)
{
	int		**tab;
	int		i;

	i = 0;
	tab = (int **)ft_calloc(sizeof(int *), data->height);
	if (!tab)
		return (0);
	while (i < data->height)
	{
		tab[i] = (int *)ft_calloc(sizeof(int), data->width);
		if (!tab[i])
			return (0);
		i++;
	}
	return (tab);
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

int	ft_close(void)
{
	exit(0);
}
