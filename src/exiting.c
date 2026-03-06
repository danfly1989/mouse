/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:46:41 by akjoerse          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:56 by codex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ptr_free(void *struct_ptr)
{
	if (struct_ptr || struct_ptr != NULL)
	{
		free(struct_ptr);
		return (1);
	}
	return (0);
}

void	cub_free(t_cub *c)
{
	debug("in 'cub_free'");
	debug(RED"attempting to free `cub`");
	free(c);
	debug("leaving'cub_free'");
}

void	cub_exit(t_cub *c)
{
	debug(BLU"in 'cub_exit'");
	mlx_destroy_window(c->mlx->mlx, c->mlx->win);
	mlx_destroy_image(c->mlx->mlx, c->mlx->img);
	mlx_destroy_display(c->mlx->mlx);
	ptr_free(c->mlx->mlx);
	ptr_free(c->mlx);
	debug(BLU"leaving 'cub_exit'");
	exit(0);
}
