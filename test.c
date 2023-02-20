#include "fdf.h"
// #include "mlx.h"
#include <stdlib.h>

typedef struct	s_data {
	void	*mlx;
	void	*win;
}				t_data;

void draw_line(t_data *data, int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps;
	float x_inc, y_inc;
	float x = x1, y = y1;
	
	// Determine the number of steps
	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else {
		steps = abs(dy);
	}
	
	// Calculate the increments
	x_inc = (float)dx / steps;
	y_inc = (float)dy / steps;
	
	// Draw the line
	for (int i = 0; i < steps; i++) {
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
		x += x_inc;
		y += y_inc;
	}
}

int main(void)
{
	t_data data;
    int height;
    int width;
	
	// Initialize MLX
    height = 
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "DDA Line Algorithm");
	
	// Draw a line
	draw_line(&data, 400, 400, 200, 200);
	
	// Display the window
	mlx_loop(data.mlx);
	
	return (0);
}
