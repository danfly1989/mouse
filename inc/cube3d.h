/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:53:13 by akjoerse          #+#    #+#             */
/*   Updated: 2026/02/25 18:20:04 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE3D_H
# define CUBE3D_H
//standard library inclusions
# include <stdlib.h>
# include <stdbool.h>
//information about the 'guy', like position, direction, field of view
# include "guy.h"
//minilibx library header - gotta have that
# include "mlx.h"
# include "libft.h"

//default width and height of the window
# define DEFWID 800
# define DEFHEI 800

//pretty colors
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define BLU "\033[1;34m"
# define DEF "\033[0m"

# define DUMMY_MAP "map/12x12.map"

//12x12 map with walls and guy facing north
/*
111111111111
100000000001
100000000001
100000000001
100000000001
10000N000001
100000000001
100000000001
100000000001
100000000001
100000000001
111111111111
*/
//structure to hold data for cube3d execution
typedef	struct	s_cub
{
	struct s_mlx	*mlx;
	struct s_guy	*guy;
	struct s_map	*map;
}				t_cub;

//comments valid for for dummy map `12x12.cub`
typedef	struct	s_map
{
	bool			valid;
	struct s_guy	*guy;
	char			*file;//12x12.cub
	char			*textures[4];
	/*{"textures/brickwall.png", "textures/claywall.png",
	"textures/forest.png", "textures/trip.png"}*/
	int			*colors[2];
	int			map_start_line;//
	int			map_end_line;
	int			yMax;
	int			xMax;
	int			**lines;
	int			***cell;
}				t_map;

//structure to hold data for 'garbage collection'
// typedef	struct	s_gbg
// {
// 	int			num;
// 	void			*data;
// 	struct s_gbg	*next;
// }				t_gbg;

//structure to hold data needed by minilibx
typedef	struct	s_mlx
{
	char			*adr;
	void			*win;
	void			*mlx;
	void			*img;
	int			len;
	int			bpp;
	int			end;
	int			err;
}				t_mlx;

//drawing.c		- drawing the image
void	draw_background(void *mlx, void *win);
void	init_mlx(t_cub *c);

//keyhooks.c	- handling key input
int	keychain(int key, void *param);
int	close_handler(void *param);
//exiting.c		- gently exiting the program
int	ptr_free(void *struct_ptr);
void	cub_exit(t_cub *c);
void	cub_free(t_cub *c);
//error.c		- various error reporting and debug functions
void	error(char *msg);
//debug with green color and BLUUUUUUE number for loops
void	debug_i(char *msg, int i);
//debug with green color
void	debug(char *msg);
//initializing the `t_cub` structure
t_cub	*init_cub(void);


#endif
//&$`~*@^%|header file for PROJECT NAME project at 42berlin by akjoerse|%^@*~`$&//