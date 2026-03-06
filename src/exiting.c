/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:46:41 by akjoerse          #+#    #+#             */
/*   Updated: 2026/02/25 14:44:35 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ptr_free(void *struct_ptr)
{
	if (struct_ptr || struct_ptr != NULL)
	{
		free (struct_ptr);
		return (1);
	}
	return (0);
}
//a rudimentary 'garbage collector' that takes what has been stored and frees it
void	cub_free(t_cub *c)
{
	debug("in 'cub_free'");
	// if (!c->gbg)
	// 	return (debug(YLW"failed cus no garbage"));
	// debug(RED"attempting to empty garbage");
	// empty_garbage(c->gbg);
	debug(RED"attempting to free `cub`");
	free (c);
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
	exit (0);
}
