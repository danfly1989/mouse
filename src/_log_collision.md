#	collision detection

##	log
###	update 2026.03.05 19:03:46
after adding an offset to the angle which the player starts at, we have avoided the issue of clipping when the player walks straight forward immediately following spawn.

repeated alterations to the "pos-x/y" coordinates did not yield satisfying results
interesting bugs were found:

	double offset = <1.5
		no visible change, player still clips into wall when walking straight
	double offset = 3.0
		corridors of 1 tile would be drawn instead as walls
	double offset = 10.0
		player would spawn in a box

####	planned update 2026.03.05 19:06:45
to improve performance, this topic should be revisited;
proposed avenues to follow:

	proceed with customary checking for `is_wall` and draw frame as expected.
		immediately check coordinates are within collision box as defined
		alter position to include offset in dominant direction

##	[further work will be done on mouse movement](_log:mouse.md#)  

######	coordinates available:
######	game->map_width
######	game->map_height

##	coordinates available:
######	game->map_width
<!-- comes from scanning the map, is a whole integer of the max index of columns found:
straightforwardly:
example: there are 90 possible indices for a point on the map with x-coordinates between 0 and `map_width` (valid or not). `map_width = 90`
then, to prevent clipping, the player should only move on the x-axis if their final x-position is within the bounds of minimum (0) and maximum (90) plus an offset distance (hitbox)
-->
######	game->map_height
<!-- comes from scanning the map, is a whole integer of the max index of rows found;
straightforwardly:
example: there are 90 possible indices for a point on the map with y-coordinates between 0 and `map_height` (valid or not): `map_height = 90`;
then, to prevent clipping, the player should only move on the x-axis if their final x-position is within the bounds: of minimum (0) and maximum (90) plus an offset distance (hitbox)
in code:
`void	handle_movement(game, map)`
`if(no_coll(new_x, new_y, map))`
`	move_player(new_x, new_y, map);`
``
``
``
``
``
``
``
``
``
``
``
``
-->

<!-- width
	// game->map_width = 0;
	// 
	// while (i < game->map_height)
	// 
	// game->map_width = len;
	// 
	// game->map_Xlim = len;
	
height
	// t_game	game;
	// game->map_height
	// game->map
	// int	start, height, i;
	// start;
	// height;
	// i;
	// game->;
	// char	**lines;
	// set_map_width(game); -->

#	changes 2026.03.05 17:52:11
##	[added a layer between input and movement](input.c#L55)  

<!-- old keypress handle -- 
int	handle_keypress(int keycode, t_game *game)
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
} -->