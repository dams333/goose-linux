/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:13:07 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 22:42:33 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/extensions/Xfixes.h>

#include "goose.h"

#include <unistd.h>

int	main(void)
{	

	t_xvar					*mlx_ptr;
	t_win_list				*w_list;
	int						size_x;
	int						size_y;
	void					*img;

	mlx_ptr = mlx_init();
	XSynchronize(mlx_ptr->display, 1);
	if (!mlx_ptr)
		return (0);
	img = mlx_xpm_file_to_image(mlx_ptr, "res/goose.xpm", &size_x, &size_y);
	w_list = mlx_new_window_fullscreen(mlx_ptr, "Goose");
	mlx_put_image_to_window(mlx_ptr, w_list, img, 0, 0);
	if (!mlx_ptr->win_list)
	{
		destroy_everything(mlx_ptr, w_list);
		return (0);
	}
	char *coucou = malloc(500);
	XGetErrorText(mlx_ptr->display, 130, coucou, 500);
	coucou[499] = 0;
	printf("%s\n", coucou);
	sleep(2);
	destroy_everything(mlx_ptr, w_list);
}
