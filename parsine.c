/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:29:28 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/17 04:07:30 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	str_length(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			len++;
		i++;
	}
	return (len);
}

void	check_lenght_of_map(char **av, int fd)
{
	size_t	len;
	size_t	len1;
	char	*str;

	str = get_next_line(fd);
	len = str_length(str);
	str = get_next_line(fd);
	while (str)
	{
		len1 = str_length(str);
		if (len > len1)
			return (ft_putendl_fd("Found wrong line length.", 1), exit(1));
		str = get_next_line(fd);
	}
}

void	check_name_of_map(char *str, char *find)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (str[i] && find[j])
	{
		while (str[i] != '.')
			i--;
		if (str[i] == '.')
		{
			while (str[i])
			{
				if (str[i] != find[j])
					return (ft_putstr_fd("no such file: ", 1),
						ft_putendl_fd(str, 1), exit(1));
				i++;
				j++;
			}
		}
	}
}

void	ft_check_map_is_valid(char **av, int fd)
{
	int		i;
	char	*str;

	i = 0;
	check_name_of_map(av[1], ".fdf");
	if (fd < 0)
		return (ft_putstr_fd("no such file: ", 1),
			ft_putendl_fd(av[1], 1), exit(1));
	check_lenght_of_map(av, fd);
	str = get_next_line(fd);
	while (str)
	{
		i = -1;
		while (str[++i])
		{
			if (!ft_isdigit(str[i]) && str[i] != '\n' && str[i] != ' ')
				return (ft_putendl_fd("Error", 1), exit(1));
		}
		str = get_next_line(fd);
	}
}
