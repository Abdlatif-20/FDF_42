/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:50:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/19 18:21:58 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	len_new_line(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			len++;
		i++;
	}
	return (len);
}

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

void	check_lenght_of_map(int fd, t_data	*data)
{
	int		len[3];
	int		height;
	char	*str;

	str = get_next_line(fd);
	if (!str || str[0] == '\n')
		return (ft_putendl_fd("Found empty Map or wrong line.", 2), exit(1));
	len[2] = str_length(str);
	free(str);
	len[0] = len_new_line(str);
	str = get_next_line(fd);
	height = 1;
	while (str && ++height)
	{
		len[0] += len_new_line(str);
		len[1] = str_length(str);
		if (len[2] > len[1])
			return (ft_putendl_fd("Found wrong line.", 2), exit(1));
		free(str);
		str = get_next_line(fd);
	}
	if (len[0] >= height)
		return (ft_putendl_fd("Found empty line", 2), exit(1));
	data->height = height;
	data->width = len[2];
}

void	check_name_of_map(char *str, char *find)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (str[i] || find[j])
	{
		while (str[i] != '.')
			i--;
		if (i < 0)
			return (ft_putendl_fd("Wrong file extension.", 2), exit(1));
		if (str[i] == '.' && i >= 0)
		{
			if (str && str[0] == '.')
				return (ft_putendl_fd("Wrong name of file.", 2), exit(1));
			while (str[i])
			{
				if (str[i] != find[j])
					return (ft_putendl_fd("Wrong file extension.", 2), exit(1));
				i++;
				j++;
			}
		}
	}
}

void	ft_check_map_is_valid(char **av, int fd, t_data *data)
{
	int		i;

	i = 0;
	check_name_of_map(av[1], ".fdf");
	fd = open(av[1], O_RDONLY, 777);
	if (fd < 0)
		return (ft_putstr_fd("no such file: ", 2),
			ft_putendl_fd(av[1], 2), exit(1));
	check_lenght_of_map(fd, data);
	close(fd);
}
