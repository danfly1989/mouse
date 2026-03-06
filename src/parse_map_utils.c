/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:24:33 by daflynn           #+#    #+#             */
/*   Updated: 2026/03/05 19:02:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse_map_utils.h"

int	count_map_rows(char **lines, int start)
{
	int	count;

	count = 0;
	while (lines[start + count] && lines[start + count][0] != '\0')
		count++;
	return (count);
}

// void	set_map_width(t_game *game)
/* legacy
{
	int	i;
	int	len;

	i = 0;
	game->map_width = 0;
	//this limit seems arbitrary: there is no reason the map should be taller than it is wide
	while (i < game->map_height)
	{
		len = ft_strlen(game->map[i]);
		if (len > game->map_width)
		{
			game->map_width = len;
		}
		i++;
	}
	game->map_Xlim = len;
} */
// new
// // [ss](#L40)

// void	set_map_width(t_game *game)
// {}

void	set_ns_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->dir_x = 0.017452;
		game->dir_y = -0.999848;
		game->plane_x = 0.659899;
		game->plane_y = 0.011519;
	}
	else
	{
		game->dir_x = -0.017452;
		game->dir_y = -0.999848;
		game->plane_x = 0.659899;
		game->plane_y = -0.011519;
	}
}

void	set_player_direction(t_game *game, char c)
{
	if (c == 'N' || c == 'S')
		set_ns_direction(game, c);
	else
	{
		game->dir_y = 0.011519;
		if (c == 'E')
		{
			game->dir_x = 0.999848;
			game->plane_y = 0.659899;
		}
		else
		{
			game->dir_x = -0.999848;
			game->plane_y = -0.659899;
		}
		game->plane_x = 0.011519;
	}
}
