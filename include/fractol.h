#ifndef	FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_instance
{
	t_img	img;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		type;
	int		y_off;
	int		x_off;
	int		zoom_level;
}				t_instance;

int			pixel_to_image(t_data *data, int x, int y, int color);
void		key_handling(int keycode, t_instance *game);
void		mouse_handling(int keycode, t_instance *game);
void		close_handling(int keycode, t_instance *game);
t_instance	*game_init(t_instance *game);
t_instance	*ft_fractol(t_instance *game);
t_instance	*init_arg(int ac, char **av);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

