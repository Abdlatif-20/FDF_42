
void display_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%d ", data->tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	int	**tab;
	int	fd;
	int	i;
	int	j;
	int	height_len;
	int	width_len;

	if (ac != 2)
		return (ft_putendl_fd("Usage: ./fdf <filename>", 1), exit(1), 0);
	fd = open(av[1], O_RDONLY, 777);
	ft_check_map_is_valid(av, fd);
	tab = map_allocate(av[1], fd, tab);
	fill_map(av[1], fd, tab);
	height_len = get_height(av[1], fd);
	width_len = get_width(av[1], fd);
	i = 0;
	while (i < height_len)
	{
		j = 0;
		while (j < width_len)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}