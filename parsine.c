/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:29:28 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/15 02:17:47 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_name_of_map(char *str, char *find)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str[i])
	{
		while (str[i] != '.')
			i++;
		if (str[i] == '.')
		{
			while (str[++i] && find[++j])
			{
				if (str[i] != find[j])
				{
					return (0);
				}
			}
		}
	}
	return (1);
}

int	ft_check_map_is_valid(char **av)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	if (!check_name_of_map(av[1], "fdf"))
		return (0);
	fd = open(av[1], O_RDONLY, 777);
	if (fd < 0)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	str = get_next_line(fd);
	while (str)
	{
		i = -1;
		while (str[++i])
		{
			if (!ft_isdigit(str[i]) && str[i] != '\n' && str[i] != ' ')
				return (0);
		}
		str = get_next_line(fd);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	printf("%d", ft_check_map_is_valid(av));
}
