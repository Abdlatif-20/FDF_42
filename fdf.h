/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:31:02 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/20 19:24:52 by aben-nei         ###   ########.fr       */
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

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef	struct	s_data {
	void	*mlx;
	void	*win;
	int		**tab;
}				t_data;


void	ft_check_map_is_valid(char **av, int fd);
int     str_length(char *str);
int		get_height(char *av, int fd);
int		get_width(char *av, int fd);
void	drawing_line(int X1, int Y1, int X2, int Y2, t_data *data);
void	ft_draw_map(t_data *data, int hight, int width);
#endif
