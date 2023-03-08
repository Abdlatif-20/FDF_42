/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:31:02 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/08 19:23:57 by aben-nei         ###   ########.fr       */
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
# include "../Bonus/fdf_bonus.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

void	ft_check_map_is_valid(char **av, int fd, t_data *data);
int		str_length(char *str);
void	drawing_line(t_point p1, t_point p2, t_data *data);
void	ft_draw_map(t_point p1, t_point p2, t_data *data);
void	drawing_line(t_point p1, t_point p2, t_data *data);
void	ft_rotate_x(t_point *p1, t_point *p2, t_data *data);
void	ft_rotate_y(t_point *p1, t_point *p2, t_data *data);
int		key_hook(int keycode, t_data *data);
#endif
