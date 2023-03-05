/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:50:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/05 19:53:30 by aben-nei         ###   ########.fr       */
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
		if ((str[i] != ' ' && str[i + 1] == ' ') || str[i + 1] == '\0')
			len++;
		i++;
	}
	return (len);
}

void	check_lenght_of_map(int fd)
{
	size_t	len;
	size_t	len1;
	char	*str;

	str = get_next_line(fd);
	if (str[0] == '\n')
		return (ft_putendl_fd("Found empty line.", 1), exit(1));
	len = str_length(str);
	str = get_next_line(fd);
	while (str)
	{
		len1 = str_length(str);
		if (len > len1)
			return (ft_putendl_fd("Found empty line.", 1), exit(1));
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
		if (i < 0)
			return (ft_putstr_fd("no such file: ", 1),
				ft_putendl_fd(str, 1), exit(1));
		if (str[i] == '.' && i >= 0)
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

	i = 0;
	check_name_of_map(av[1], ".fdf");
	fd = open(av[1], O_RDONLY, 777);
	if (fd < 0)
		return (ft_putstr_fd("no such file: ", 1),
			ft_putendl_fd(av[1], 1), exit(1));
	check_lenght_of_map(fd);
	close(fd);
}
