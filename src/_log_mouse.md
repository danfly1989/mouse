####	[did you come from here?](_log:collision.md#)  

#	introduction
mouse movement is registered as:

##	log
###	update 2026.03.05 19:27:14
####	definitions
#####	mouse movements
7	enters window 1L<<4
8	leaves window 1L<<5

//mouse movement
mlx_hook(win, 6, 1L<<6, mouse_move, data);
//mouse movement handler
int mouse_move(int x, int y, void *param);
//previous mouse movement
///variable in map or game struct
////[initialization]()
////[cleanup in cleanup.c](cleanup.c#)?
#####	mouse clicks
//click (button pressed)
// mlx_hook(win, 4, 1L<<2, mouse_press, data);
//unclick (finger lifted)
// mlx_hook(win, 5, 1L<<3, mouse_release, data);
####	changes
#####	[int	handle_keypress(int keycode, t_game *game)](input.c#L166)
added:
int	handle_click(int click, int x, int y, t_game *game);
int	handle_mouse(int x, int y, t_game *game)
#####	[void	init_game(t_game *game)](main.c#L20)  
added:
	
	game->mouse_x = game->screen_width / 2;
	game->mouse_y = game->screen_height / 2;

but:
if the players mouse pointer starts outside the frame
	when the players mouse pointer enters the frame
		set the default x/y position to be
			a - the accurate coords
			b - he middle
if the players mouse pointer starts inside the frame
	when the players mouse pointer leaves the frame

if the 
#####	[int	main(int argc, char **argv)](main.c#L70)  
added:
mlx_hook(game.win, 6, 1L << 6, handle_mouse, &game);
######	[potential additions: mouse_press]
######	[potential additions: mouse_release]

#####	[cub3d.h](../inc/cub3d.h#L90)  
added:
int	handle_click(int click, int x, int y, t_game *game);
int	handle_mouse(int x, int y, t_game *game);
####	