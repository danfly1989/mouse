/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:13:57 by akjoerse          #+#    #+#             */
/*   Updated: 2026/02/25 14:35:51 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_mlx(t_cub *c)
{
	debug(BLU"entering 'init_mlx'");
	t_mlx	*m;

	debug("attempting to allocate `t_mlx *m`");
	m = malloc(sizeof(t_mlx));
	if (!m || m == NULL)
		exit (0);//TODO:integrate into exit function
	m->win = NULL;
	m->mlx = NULL;
	m->img = NULL;
	m->adr = NULL;
	m->len = 0;
	m->bpp = 0;
	m->err = 0;
	m->end = 0;
	debug(YLW"attempting to call `mlx_init`");
	m->mlx = mlx_init();
	debug(YLW"attempting to call `mlx_new_window`");
	m->win = mlx_new_window(m->mlx, DEFWID, DEFHEI, "Hello Cub3D");
	debug(YLW"attempting to call `mlx_new_image`");
	m->img = mlx_new_image(m->mlx, DEFWID, DEFHEI);
	debug("setting `cub->mlx = m`");
	c->mlx = m;
	debug(BLU"leaving 'init_mlx'");
}
