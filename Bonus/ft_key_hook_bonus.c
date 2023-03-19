/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:29:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/19 18:20:27 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	key_hook2(t_data *data)
{
	if (data->flag_projection == 1)
		data->flag_projection = 0;
	else
		data->flag_projection = 1;
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, 5120 / 2, 2880 / 2);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	ft_draw_map(data->point2, data->point2, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	key_hook1(int keycode, t_data *data)
{
	if (keycode == Z_PLUS)
	{
		data->zoom_z += 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == Z_MINUS)
	{
		data->zoom_z -= 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, 5120 / 2, 2880 / 2);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_draw_map(data->point2, data->point2, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}

int	key_hook(int keycode, t_data *data)
{
	print_keycode_event(keycode);
	if (keycode == ESC)
		exit(0);
	if (keycode == SPEED_UP)
		data->speed_up += 1.5;
	if ((keycode >= LEFT && keycode <= UP) || keycode == A_LEFT
		|| keycode == D_RIGHT || keycode == Z_DOWN || keycode == W_UP)
		ft_translate(keycode, data);
	else if (keycode == PLUS || keycode == MINUS)
		ft_zoom(keycode, data);
	else if (keycode == SPACE)
		ft_reset(data);
	else if (keycode == ROTATE_X)
		rotate_x(data);
	else if (keycode == ROTATE_Y)
		rotate_y(data);
	else if (keycode == COLOR)
		ft_color(data);
	else if (keycode == Z_PLUS || keycode == Z_MINUS)
		key_hook1(keycode, data);
	else if (keycode == PROJECTION)
		key_hook2(data);
	return (0);
}
