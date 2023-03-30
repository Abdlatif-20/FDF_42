/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:31:02 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/28 23:33:24 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ESC 53
# define UP 126
# define W_UP 13
# define DOWN 125
# define Z_DOWN 6
# define LEFT 123
# define A_LEFT 0
# define RIGHT 124
# define D_RIGHT 2
# define PLUS 69
# define MINUS 78
# define SPACE 49
# define ROTATE_X 15
# define ROTATE_Y 14
# define ROTATE_Z 7
# define COLOR 3
# define Z_PLUS 5
# define Z_MINUS 4
# define PROJECTION 38
# define SPEED_UP 1
# define MOUSE_SCROLL_UP 5
# define MOUSE_SCROLL_DOWN 4
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2

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
	int		change_color;
	int		**tab;
	double	speed_up;
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
	int		zoom_z;
	int		dx;
	int		dy;
	int		flag_projection;
	int		flag_x;
	int		flag_y;
	int		key_code;
	t_point	point1;
	t_point	point2;
}				t_data;

void	ft_check_map_is_valid(char **av, int fd, t_data *data);
int		**map_allocate(t_data *data);
void	fill_map(char *av, int fd, int **map);
int		str_length(char *str);
void	drawing_line(t_point p1, t_point p2, t_data *data);
void	ft_draw_map(t_point p1, t_point p2, t_data *data);
void	ft_rotate_x(t_point *p1, t_point *p2, t_data *data);
void	ft_rotate_y(t_point *p1, t_point *p2, t_data *data);
int		mouse_hook(int event, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
void	ft_translate(int keycode, t_data *data);
void	ft_zoom(int keycode, t_data *data);
void	ft_reset(t_data *data);
void	ft_rotate_x(t_point *p1, t_point *p2, t_data *data);
void	ft_rotate_y(t_point *p1, t_point *p2, t_data *data);
void	rotate_x(t_data *data);
void	rotate_y(t_data *data);
void	ft_color(t_data *data);
int		ft_close(void);
void	free_tab(char **tab);
void	print_keycode_event(int keycode);

#endif
