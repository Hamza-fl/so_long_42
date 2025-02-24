#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/ft_printf/ft_printf.h"
# define TILE_SIZE 32
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef struct s_images
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*floor;
}	t_images;

typedef struct s_map
{
	char	**matrice;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_images	imgs;
	int			player_x;
	int			player_y;
	int			moves;
	int			collectibles;
	int			total_collectibles;
	int			player_count;
	int			exit_count;
	int			game_won;
}	t_game;

int	ft_strcmp(char *s1, char *s2);
int	handle_errors(int ac, char *file);
int	setup_game(t_game *game, char *file);

#endif