#ifndef	FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_ITERATION 100
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
	double	zoom_level;
	t_img	img;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		type;
	int		y_off;
	int		x_off;
}				t_instance;

t_instance	*init_arg(int ac, char **av, t_instance *game);
t_instance	*game_init(t_instance *game);
t_instance	*img_init(t_instance *game);
t_instance	*ft_newinstance(void);
void		pixel_to_image(t_img *data, int x, int y, int color);
void		zoom_out(t_instance	*game, int x, int y);
void		zoom_in(t_instance	*game, int x, int y);
void		put_set_to_image(t_instance *game);
int			mouse_handling(int button, int x, int y, t_instance *game);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			mandelbrot_set(t_instance *game, int x, int y);
int			key_handling(int keycode, t_instance *game);
int			ft_fractol(t_instance *game, int x, int y);
int			close_handling(t_instance *game);
int			get_type(const char *s);
int			ft_atoi(const char *s);
int			julia_set(t_instance *game, int x, int y);

#endif
