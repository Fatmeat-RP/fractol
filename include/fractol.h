#ifndef	FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

# if __APPLE__

#  define KEY_ESC 			53
#  define KEY_ARROW_UP		126
#  define KEY_ARROW_DOWN	125
#  define KEY_ARROW_LEFT	123
#  define KEY_ARROW_RIGHT	124
#  define KEY_M				46
#  define KEY_J				38
#  define KEY_C				8
#  define RIGHT_BUTTON		2
#  define LEFT_BUTTON		1
#  define NORTH_SCROLL		4
#  define SOUTH_SCROLL		5

# elif __linux__

#  define KEY_ESC			65307
#  define KEY_ARROW_UP		65362
#  define KEY_ARROW_DOWN	65364
#  define KEY_ARROW_LEFT	65361
#  define KEY_ARROW_RIGHT	65363
#  define KEY_M				109
#  define KEY_J				106
#  define KEY_C				8
#  define RIGHT_BUTTON		3
#  define LEFT_BUTTON		1
#  define NORTH_SCROLL		4
#  define SOUTH_SCROLL		5

# endif


# define MAX_ITERATION 70

# define PINK	5
# define GREEN	6
# define BLUE	7
# define BROWN	8
# define RED	9

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
	double		zoom_level;
	t_img		img;
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	int			type;
	long double	y_off;
	long double	x_off;
	long double	resratio;
	long double	julia_x;
	long double	julia_y;
	int			color;
	int			*palette;
}				t_instance;

typedef struct	s_double
{
	long double	yscale;
	long double	xscale;
	long double	x0;
	long double	y0;
	long double	ratio;
	long double	tmp;
}				t_double;

/**
 * @brief read the programme arguments and check that they are correct for 
 * the programme use case 
 * 
 * @param ac arguments
 * @param av number of arguments
 * @param game this is a t_instance structure
 * @return t_instance* 
 */
t_instance	*init_arg(int ac, char **av, t_instance *game);
/**
 * @brief initialize a new mlx context and a new window in the game t_instance structure
 * 
 * @param game this is a t_instance structure
 * @return t_instance* 
 */
t_instance	*game_init(t_instance *game);
/**
 * @brief initialize a new image in the game t_instance structure
 * 
 * @param game this is a t_instance structure
 * @return t_instance* 
 */
t_instance	*img_init(t_instance *game);
/**
 * @brief initialize a new t_instance structure
 * 
 * @return t_instance* 
 */
t_instance	*ft_newinstance(void);
void		pixel_to_image(t_img *data, int x, int y, int color);
void		get_palette(char *s, t_instance *game);
void		zoom_out(t_instance *game, int x, int y);
void		zoom_in(t_instance *game, int x, int y);
void		put_set_to_image(t_instance *game);
void		set_palette(int *palette, t_instance *game);
int			mouse_handling(int button, int x, int y, t_instance *game);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			mandelbrot_set(t_instance *game, int x, int y);
int			get_type(char **av, t_instance *game, int ac);
int			mouse_moving(int x, int y, t_instance *game);
int			key_handling(int keycode, t_instance *game);
int			ft_fractol(t_instance *game, int x, int y);
int			julia_set(t_instance *game, int x, int y);
int			close_handling(t_instance *game);
int			init_palette(int color, t_instance *game);
int			ft_atoi(const char *s);

#endif
