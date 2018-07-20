/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:12:25 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:14:21 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_wolf3d		*init_wolf3d(void)
{
	t_wolf3d	*wolf3d;

	wolf3d = (t_wolf3d *)malloc(sizeof(t_wolf3d));
	MLX = NULL;
	WIN = NULL;
	IMG = 0;
	IMG_P = NULL;
	MX = 0;
	MY = 0;
	return (wolf3d);
}

void			init_window(t_wolf3d *wolf3d)
{
	int			endian;
	int			bpp;
	int			size_line;

	endian = 0;
	bpp = 32;
	size_line = WIDTH;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "Wolf3D");
	IMG_P = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG = (int *)mlx_get_data_addr(IMG_P, &bpp,
	&size_line, &endian);
	//work_with_threads(wolf3d);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	mlx_hook(WIN, 2, 0, hook, wolf3d);
	// mlx_mouse_hook(WIN, mouse_hook, wolf3d);
	mlx_hook(WIN, 17, 1L << 17, exit_button, 0);
	mlx_loop(MLX);
}
