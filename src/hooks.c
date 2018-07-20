/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:14:44 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:17:41 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		change_position(int key, t_wolf3d *wolf3d)
{
	double		move;

	move = 0.1;
	if (key == 123)
		MX -= move;
	else if (key == 124)
		MX += move;
	else if (key == 125)
		MY += move;
	else if (key == 126)
		MY -= move;
}


int				hook(int key, t_wolf3d *wolf3d)
{
	mlx_clear_window(MLX, WIN);
	if (key == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	else if (key == 123 || key == 124 ||
			key == 125 || key == 126)
		change_position(key, wolf3d);
	//work_with_threads(wolf3d);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	return (0);
}
