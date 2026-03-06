/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:19:05 by akjoerse          #+#    #+#             */
/*   Updated: 2026/02/25 14:34:13 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// legend:
///	65307 = [ESC]
int	keychain(int key, void *param)
{
	if (key == 65307 || !param)
		close_handler(param);
	return (0);
}

int	close_handler(void *param)
{
	t_cub	*cub;

	cub = param;
	// mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
	debug("in `close_handler` trying to call cub_exit");
	cub_exit(param);
	return (0);
}