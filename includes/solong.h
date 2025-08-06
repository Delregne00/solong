/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 solong.h											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 14:44:17 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 14:44:17 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// Definiciones de constantes
# define WIDTH 3840
# define HEIGHT 2160
# define TILE_WIDTH 140
# define TILE_HEIGHT 140
# define MAP_WIDTH 23
# define MAP_HEIGHT 23
# define OFFSET_X 1665
# define OFFSET_Y -470
# define TOMB_SPRITES 20
# define TOMB_SPEED 1
# define TOMB_X_POSITION 100
# define TOMB_Y_POSITION 1450
# define TOMB_FRAME_DELAY 4
# define TOMB_SCALE 1
# define NORTH 0
# define WEST 1
# define SOUTH 2
# define EAST 3
# define UP 0
# define RIGHT 1
# define DOWN 2
# define LEFT 3

typedef struct s_tomb
{
	mlx_image_t	*images[TOMB_SPRITES];
	int			x;
	int			y;
	int			frame;
	int			frame_counter;
}				t_tomb;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	current_direction;
}		t_enemy;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		enemies;
	char	last_terrain;
	char	exit;
	t_enemy	*enemy;
}			t_map;

typedef struct s_iso_coords
{
	int	x;
	int	y;
	int	wall;
	int	moviments;
}		t_iso_coords;

typedef struct s_sprites
{
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*brick;
	mlx_image_t	*cloud;
	mlx_image_t	*cloud_1;
	mlx_image_t	*person;
	mlx_image_t	*person_flip;
	mlx_image_t	*enemy;
	mlx_image_t	*special_object;
	mlx_image_t	*moon;
	mlx_image_t	*succes;
	mlx_image_t	*death;
}				t_sprites;

typedef struct s_game
{
	t_map			*map;
	mlx_t			*mlx;
	t_sprites		*sprites;
	t_tomb			*tomb;
	t_iso_coords	*pos;
	char			*moves_str;
	int				dx;
	int				dy;
	int				person_direction;
	int				move_count;
	int				get_collect;
	int				succes;
	int				death;
}					t_game;

void			init_game(t_game *game);
void			cleanup_game(t_game *game);
int				parser(char *line);
void			check_dimensions(int fd, t_map *map);
void			count_elements(t_map *map);
void			create_map(int fd, t_map *map);
void			free_map(t_map *map);
int				is_valid_pos(t_map *map, int x, int y);
void			load_tomb_sprites(mlx_t *mlx, t_tomb *tomb);
void			animate_tomb(void *param);
void			initialize_tomb_images(mlx_t *mlx, t_tomb *tomb);
mlx_image_t		*load_image(mlx_t *mlx, const char *path);
t_iso_coords	cart_to_iso(int x, int y);
void			update_move_counter(mlx_t *mlx, int move_count);
void			clear_window(mlx_t *mlx, t_sprites sprites);
void			render_map_isometric(mlx_t *mlx, t_sprites sprites, t_map *map);
void			move_person(t_game *game);
void			key_hook(mlx_key_data_t keydata, void *param);
void			patrol_enemies(t_map *map);
void			delete_images(mlx_t *mlx, t_sprites *sprites);
void			reload_images(mlx_t *mlx, t_sprites *sprites);
void			fill_enemies_data(t_map *map);
void			init_enemies(t_map *map);
void			free_enemies(t_map *map);
void			get_next_position(int direction, int *x, int *y);
void			find_tomb(t_map *map);
void			finish_move_process(t_game *game);
void			render_background(mlx_t *mlx, t_sprites sprites);
void			render_player(mlx_t *mlx, t_sprites sprites, t_iso_coords pos);
void			render_brick(mlx_t *mlx, t_sprites sprites, t_iso_coords pos);
void			loop_grave(void *param);
void			handle_collectible(t_map *map, int x, int y);
void			re_render_map_isometric(mlx_t *mlx,
					t_sprites *sprites, t_map *map);
void			handle_key_press(t_game *game, int key);
void			update_player_position(t_map *map, int new_x, int new_y);
void			handle_player_move(t_map *map, int new_x,
					int new_y, int *book_flag);
char			*get_sprite_direction(int direction);
bool			load_sprites(mlx_t *mlx, t_sprites *sprites);
int				check_move(t_map *map, int new_x, int new_y);
int				is_valid_position(char cell_type);
int				is_valid_cell(char cell, mlx_t *mlx, t_game *game);
int				can_move(t_map *map, int x, int y, int direction);
int				check_map_accessibility(t_map *map);
int				check_map_borders(t_map *map);

#endif
