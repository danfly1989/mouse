/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:35:01 by daflynn           #+#    #+#             */
/*   Updated: 2026/03/05 21:02:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MOVE_SPEED 0.05
#define ROT_SPEED  0.03
#define MOUSE_SENS 0.003
#define ESC_KEY    65307
#define LEFT_KEY   65361
#define RIGHT_KEY  65363
// int	no_coll(t_dir dir, t_/*  */game *game, double new_x, double new_y);

/*
`void	handle_movement(game, map)`
`if(no_coll(new_x, new_y, map))`
`	move_player(new_x, new_y, map);`
`if(no_coll(new_x, new_y, map))`
*/
/* int	no_coll(t_dir dir, t_game *game, double new_x, double new_y)
{
	double	offset;

	offset = 0.3;
	if (new_x)
	return (0);
	return (1);
} */

/* testing idea
having the new x new y setting print out last set, once the wall is found.

int	g_max_x = 0;
int	g_max_y = 0;

if (g_max_x == 0)
{
	g_max_x = 1;
	printf("max_x has been reached! {}");
}
if (g_max_y == 0)
{
	g_max_y = 1;
	printf("max_y has been reached! {}");
}
 */
static void	move_player(t_game *game, double direction)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + (game->dir_x * MOVE_SPEED * direction);
	new_y = game->pos_y + (game->dir_y * MOVE_SPEED * direction);
// 	if (no_coll(game->pos_x
// game->pos_y; game->))

	//void	is_wall(t_game game, double *pos_x)
	if (!is_wall(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (!is_wall(game, game->pos_x, new_y))
		game->pos_y = new_y;
}
/* legacy 
static void	move_player(t_game *game, double direction)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + (game->dir_x * MOVE_SPEED * direction);
	new_y = game->pos_y + (game->dir_y * MOVE_SPEED * direction);
	//void	is_wall(t_game game, double *pos_x)
	if (!is_wall(game, (int)new_x, (int)game->pos_y))
		game->pos_x = new_x;
	if (!is_wall(game, (int)game->pos_x, (int)new_y))
		game->pos_y = new_y;
} */

static void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	
	old_dir_x = game->dir_x;
	game->dir_x = (game->dir_x * cos(angle)) - (game->dir_y * sin(angle));
	game->dir_y = (old_dir_x * sin(angle)) + (game->dir_y * cos(angle));
	old_plane_x = game->plane_x;
	game->plane_x = (game->plane_x * cos(angle))
		- (game->plane_y * sin(angle));
	game->plane_y = (old_plane_x * sin(angle))
		+ (game->plane_y * cos(angle));
}

/* new keypress layer
see
"_log:collision.md"
cat "./_log:collision.md"




*///*/*/*/
//*/*/*/

typedef enum	e_dir
{STILL, FORWARDS, BACKWARDS, RIGHT, LEFT, CLOCKWISE, COUNTERCLOCKWISE}t_dir;

t_dir	dir_enums(int keycode)
{
	if (keycode == 'w' || keycode == 'W')
		return (FORWARDS);
	if (keycode == 's' || keycode == 'S')
		return (BACKWARDS);
	if (keycode == LEFT_KEY || (keycode == 'a' || keycode == 'A'))
		return (COUNTERCLOCKWISE);
	if (keycode == RIGHT_KEY || (keycode == 'd' || keycode == 'D'))
		return (CLOCKWISE);
	//strafing
	// if (keycode == 'a' || keycode == 'A')
	//strafing
	// if (keycode == 'd' || keycode == 'D')

	// if (keycode == LEFT_KEY || (keycode == 'a' || keycode == 'A'))
		// return (RIGHT);
	// if (keycode == RIGHT_KEY || (keycode == 'd' || keycode == 'D'))
		// return (LEFT);
	// if (mouse == x-)
	// return (COUNTERCLOCKWISE);
	// if (mouse == x+)
		// return (CLOCKWISE);
	else
		return (STILL);
}
/* bool	no_coll(enum dir, t_game *game)
{

//6 directions
//7 enum (0 = still)

} */
/*
//mouse events
///6
////pointer moved
///7
////pointer entered window
///8
////pointer left window
//mouse movement
mlx_hook(win, 6, 1L<<6, mouse_move, data);
//mouse movement handler
int mouse_move(int x, int y, void *param);
*/
/* handle mouse */
//click (button pressed)
// mlx_hook(win, 4, 1L<<2, mouse_press, data);
//unclick (finger lifted)
// mlx_hook(win, 5, 1L<<3, mouse_release, data);
int	handle_click(int click, int x, int y, t_game *game);
/*scaling rotation


*/

int	get_abs(int	val)
{
	if (val < 0)
		return (-val);
	return (val);
}
int	handle_mouse(int x, int y, t_game *game)
{
	int		ox;
	int		nx;
	int		delta;
	double	angle;

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
	ox = game->mouse_x;
	nx = x;
	delta = nx - ox;
	angle = 0.003 * (double)delta;
	game->warping = 1;
	mlx_mouse_move(game->mlx, game->win, game->screen_width / 2, game->screen_height / 2);
	game->mouse_x = game->screen_width / 2;
	rotate_player(game, angle);
	render_frame(game);
	(void)y;
	return (1);
}

/* 
int	handle_mouse(int x, int y, t_game *game)
{
	if (!game->mouse_family)
		return (0);
	if (game->mousedelta_x == game->screen_width / 2;
	|| game->mousedelta_y == game->screen_height / 2)
	{
		game->mousedelta_x = x;
		game->mousedelta_y = y;
	}
	else
	{
	//(degrees to radians)
	//radians = pi * degrees / 180.0
	//delta should be a radian-ready number
		double	delta = 0.0;
		double	old_x = game->mousedelta_x;
		double	new_x = x;
		
		new_x = (new_x - old_x);
		delta = ROT_SPEED * new_x
		rotate_player(game, (delta * MOUSE_SENS));
		
		(void)y;	

		move_player(game, 0.0);
	}
	render_frame(game);
	return (1);
} */
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
int	handle_keypress(int keycode, t_game *game)
{
	t_dir	dir;
	if (keycode == ESC_KEY)
	{
		cleanup(game);
		exit(0);
	}
	////&& no_coll
	//move_player(game, 1.0);
	dir = dir_enums(keycode);
	// if (keycode == 'w' || keycode == 'W')
	if (dir == FORWARDS)
		move_player(game, 1.0);
	if (dir == BACKWARDS)
		move_player(game, -1.0);
	// if (dir == LEFT)
	if (dir == COUNTERCLOCKWISE)
		rotate_player(game, -ROT_SPEED);
	// if (dir == RIGHT)
	if (dir == CLOCKWISE)
		rotate_player(game, ROT_SPEED);
	render_frame(game);
	return (0);
}
/* int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		cleanup(game);
		exit(0);
	}
	if (keycode == 'w' || keycode == 'W')
		move_player(game, 1.0);
	if (keycode == 's' || keycode == 'S')
		move_player(game, -1.0);
	if (keycode == LEFT_KEY || (keycode == 'a' || keycode == 'A'))
		rotate_player(game, -ROT_SPEED);
	if (keycode == RIGHT_KEY || (keycode == 'd' || keycode == 'D'))
		rotate_player(game, ROT_SPEED);
	render_frame(game);
	return (0);
} */

int	handle_close(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}
