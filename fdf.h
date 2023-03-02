/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:31:02 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/02 08:32:33 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_point {
	int		x;
	int		y;
	int		z;
}				t_point;

typedef struct s_data {
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	void	*img;
	char	*addr;
	void	*mlx;
	void	*win;
	double	zoom;
	int		color;
	int 	change_color;
	int		**tab;
	int		height;
	int		width;
	int		move_x;
	int		move_y;
	int		steps;
	double	inc_x;
	double	inc_y;
	double	angle_x;
	double	angle_y;
	double	x;
	double	y;
	double	rotation;
	int		c;
	int		dx;
	int		dy;
	int		key_press;
	int		key_code;
	int		flag;
	int		flag1;
	int		flag2;
	t_point	point1;
	t_point	point2;
}				t_data;

void	ft_check_map_is_valid(char **av, int fd);
int		str_length(char *str);
void	get_width_height(char *av, int fd, t_data *data);
void	drawing_line(t_point p1, t_point p2, t_data *data);
void	ft_draw_map(t_data *data);
void    ft_rotate_x(t_point *p1, t_point *p2, t_data *data);
void    ft_rotate_y(t_point *p1, t_point *p2, t_data *data);

#endif
