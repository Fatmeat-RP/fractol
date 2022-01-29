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
	t_img	*img;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		type;
	int		y_off;
	int		x_off;
	int		zoom_level;
}				t_instance;

t_instance	*game_init(t_instance *game);
t_instance	*ft_fractol(t_instance *game);
t_instance	*init_arg(int ac, char **av, t_instance *game);
t_instance	*ft_newinstance(void);
t_img		*ft_newimg(void);
int			key_handling(int keycode, t_instance *game);
int			mouse_handling(int keycode, t_instance *game);
int			close_handling(t_instance *game);
int			get_type(const char *s);
int			ft_atoi(const char *s);
int			pixel_to_image(t_img *data, int x, int y, int color);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
