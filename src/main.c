/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:08:25 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:09:02 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			exit_button(int key)
{
	key = 0;
	exit(0);
}

void		print_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void		print_info(void)
{
	ft_printf("--------------------------------------------\n");
	ft_printf("Hey hey hey!👋\n");
	ft_printf("Simple guide for you.\n\n");
	ft_printf("Fractols: - julia\n");
	ft_printf("          - mandelbrot\n");
	ft_printf("          - tricorn\n");
	ft_printf("          - heart\n");
	ft_printf("          - buffalo\n");
	ft_printf("          - celtic heart\n");
	ft_printf("          - buring ship\n");
	ft_printf("          - perpendicular celtic\n\n");
	ft_printf("Actions:  - static color [1,2..7] left side on keyboard\n");
	ft_printf("          - dynamic color [+ / -]\n");
	ft_printf("          - change position [ ⬆️  ⬇️  ⬅️  ➡️  ]\n");
	ft_printf("          - zoom 🔎 [rotate 🖱  wheel]\n");
	ft_printf("          - return begining position [space]\n");
	ft_printf("          - change fractol [1,2..8] right side on keyboard\n");
	ft_printf("          - exit [esc, ❌]\n");
	ft_printf("--------------------------------------------\n");
	exit(0);
}

void		check_argument(char **argv, t_wolf3d *wolf3d)
{
	if (!ft_strcmp(argv[1], "1"))
		wolf3d->num = 1;
	else if (!ft_strcmp(argv[1], "2"))
		wolf3d->num = 2;
	else if (!ft_strcmp(argv[1], "3"))
		wolf3d->num = 3;
	else if (!ft_strcmp(argv[1], "info"))
		print_info();
	else
		print_error("Hey, you input invalid argument!😭");
}

int			main(int argc, char **argv)
{
	t_wolf3d *wolf3d;

	if (argc != 2)
		print_error("Hey, if you dont know how it works - input 'info'👌");
	else
	{
		wolf3d = init_wolf3d();
		check_argument(argv, wolf3d);
		init_window(wolf3d);
	}
	return (0);
}
