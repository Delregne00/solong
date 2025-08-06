/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 file1.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:42:52 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:42:52 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

int	is_valid_cell(char cell, mlx_t *mlx, t_game *game)
{
	t_sprites	*sprites;

	sprites = game->sprites;
	if (cell == 'e')
	{
		mlx_resize_image(sprites->death, sprites->death->width,
			sprites->death->height);
		mlx_image_to_window(mlx, sprites->death, 3000, 1300);
		game->death = 1;
	}
	if (cell == 'W')
	{
		mlx_resize_image(sprites->succes, sprites->succes->width,
			sprites->succes->height);
		mlx_image_to_window(mlx, sprites->succes, 2600, 1400);
		game->succes = 1;
	}
	return (!(cell == 'E' || cell == '1'));
}

void	handle_collectible(t_map *map, int x, int y)
{
	if (map->grid[y][x] != 'C')
		return ;
	map->collectibles--;
}

void	delete_images(mlx_t *mlx, t_sprites *sprites)
{
	mlx_delete_image(mlx, sprites->person);
	mlx_delete_image(mlx, sprites->brick);
	mlx_delete_image(mlx, sprites->enemy);
	mlx_delete_image(mlx, sprites->special_object);
}

void	reload_images(mlx_t *mlx, t_sprites *sprites)
{
	sprites->brick = load_image(mlx, "./textures/brick1.png");
	sprites->enemy = load_image(mlx, "./textures/enemy.png");
	sprites->special_object = load_image(mlx, "./textures/tomb.png");
}

char	*get_sprite_direction(int direction)
{
	if (direction == 2)
		return ("./textures/person_flip.png");
	else
		return ("./textures/person6.png");
}
