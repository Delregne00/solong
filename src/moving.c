/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 file4.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:18 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:18 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

void	find_tomb(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'E')
			{
				map->grid[y][x] = 'W';
			}
			x++;
		}
		y++;
	}
}

void	handle_player_move(t_map *map, int new_x, int new_y, int *book_flag)
{
	char	current_cell;

	current_cell = map->grid[new_y][new_x];
	map->grid[map->player_y][map->player_x] = '0';
	if (current_cell == '0')
	{
		map->grid[new_y][new_x] = 'P';
	}
	if (current_cell == 'C')
		*book_flag = 1;
}

void	update_player_position(t_map *map, int new_x, int new_y)
{
	int	book_flag;

	book_flag = 0;
	handle_player_move(map, new_x, new_y, &book_flag);
	if (book_flag == 1)
		handle_collectible(map, new_x, new_y);
	map->player_x = new_x;
	map->player_y = new_y;
	if (book_flag == 1)
		map->grid[new_y][new_x] = 'T';
}

void	finish_move_process(t_game *game)
{
	char	*sprite_path;

	is_valid_cell(game->map->grid[game->map->player_y][game->map->player_x],
		game->mlx, game);
	patrol_enemies(game->map);
	delete_images(game->mlx, game->sprites);
	sprite_path = get_sprite_direction(game->person_direction);
	game->sprites->person = load_image(game->mlx, sprite_path);
	if (game->map->collectibles == 0)
	{
		game->get_collect = 1;
	}
	reload_images(game->mlx, game->sprites);
	if (game->map->collectibles == 0)
	{
		find_tomb(game->map);
	}
	re_render_map_isometric(game->mlx, game->sprites, game->map);
}
