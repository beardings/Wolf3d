/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:07:05 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:07:52 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/header/libft.h"
# include "../libft/header/ft_printf.h"
# include "../libft/header/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <pthread.h>

# define GREEN 0x008000
# define GREEN_LIGHT 0x00FF00

# define RED 0xFF0000
# define RED_CRIMSON 0xDC143C

# define BLUE 0x4169E0
# define BLUE_LIGHT 0x00BFFF

# define WHITE 0xFFFFFF

# define WIDTH 1600
# define HEIGHT 1200

# define MLX wolf3d->mlx
# define WIN wolf3d->win
# define IMG_P wolf3d->img
# define IMG wolf3d->image
# define MX wolf3d->move_x
# define MY wolf3d->move_y

typedef	struct		s_wolf3d
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*image;
	char			num;
	double			move_x;
	double			move_y;
}					t_wolf3d;

typedef struct		s_threads
{
	t_wolf3d		*copy;
	int				thread;
	pthread_t		threads;
}					t_threads;

int					exit_button(int key);
void				print_error(char *str);
void				work_with_threads(t_wolf3d *wolf3d);
void				init_window(t_wolf3d *wolf3d);
t_wolf3d			*init_wolf3d(void);
int					hook(int key, t_wolf3d *wolf3d);

#endif
