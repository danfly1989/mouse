/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:02:44 by akjoerse          #+#    #+#             */
/*   Updated: 2026/03/06 11:02:44 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = (game->dir_x * cos(angle)) - (game->dir_y * sin(angle));
	game->dir_y = (old_dir_x * sin(angle)) + (game->dir_y * cos(angle));
	old_plane_x = game->plane_x;
	game->plane_x = (game->plane_x * cos(angle)) - (game->plane_y * sin(angle));
	game->plane_y = (old_plane_x * sin(angle)) + (game->plane_y * cos(angle));
}

static void	rotate_from_mouse(t_game *game, int x)
{
	int		delta;
	double	angle;

	delta = x - game->mouse_x;
	angle = game->mouse_sensitivity * (double)delta;
	game->warping = 1;
	mlx_mouse_move(game->mlx, game->win,
		game->screen_width / 2, game->screen_height / 2);
	game->mouse_x = game->screen_width / 2;
	rotate_player(game, angle);
}

int	handle_mouse(int x, int y, t_game *game)
{
	if (!game->mouse_family)
		return (0);
	if (game->warping)
	{
		game->warping = 0;
		return (0);
	}
	if (game->mouse_x == -1)
	{
		game->mouse_x = x;
		return (0);
	}
	rotate_from_mouse(game, x);
	render_frame(game);
	(void)y;
	return (1);
}

int	welcome_mouse(t_game *game)
{
	game->mouse_family = 1;
	game->mouse_x = -1;
	return (1);
}

int	goodbye_mouse(t_game *game)
{
	game->mouse_family = 0;
	return (1);
}
