/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:31:38 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/19 18:21:46 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mouse_hook1(int event, t_data *data)
{
	if (event == MOUSE_RIGHT)
	{
		data->move_x += 10 * data->speed_up;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (event == MOUSE_LEFT)
	{
		data->move_x -= 10 * data->speed_up;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}

void	mouse_up(t_data *data)
{
	data->move_y -= 10 * data->speed_up;
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	ft_draw_map(data->point2, data->point2, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	mouse_hook(int event, int x, int y, t_data *data)
{
	print_keycode_event(event);
	(void)x;
	(void)y;
	if (event == MOUSE_RIGHT || event == MOUSE_LEFT)
		mouse_hook1(event, data);
	if (event == MOUSE_SCROLL_DOWN)
	{
		data->move_y += 10 * data->speed_up;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(&data, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (event == MOUSE_SCROLL_UP)
		mouse_up(data);
	return (0);
}
