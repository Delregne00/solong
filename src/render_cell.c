/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 render1.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:44:09 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:44:09 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	cell(mlx_t *mlx, t_sprites *sprites, t_iso_coords pos, char cell)
{
	if (cell == 'P')
		render_player(mlx, *sprites, pos);
	if (cell == 'T')
	{
		mlx_image_to_window(mlx, sprites->cloud_1, pos.x,
			pos.wall - TILE_HEIGHT / 8);
		mlx_image_to_window(mlx, sprites->person, pos.x, pos.wall);
	}
	if (cell == 'E' || cell == 'W')
		mlx_image_to_window(mlx, sprites->special_object, pos.x, pos.wall);
	if (cell == 'e')
		mlx_image_to_window(mlx, sprites->enemy, pos.x, pos.wall);
	if (cell == '1')
		render_brick(mlx, *sprites, pos);
}

static void	re_render_row(mlx_t *mlx, t_sprites *sprites, t_map *map, int y)
{
	int				x;
	t_iso_coords	pos;

	x = 0;
	while (x < map->cols)
	{
		pos = cart_to_iso(x, y);
		cell(mlx, sprites, pos, map->grid[y][x]);
		x++;
	}
}

void	re_render_map_isometric(mlx_t *mlx, t_sprites *sprites, t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
	{
		re_render_row(mlx, sprites, map, y);
		y++;
	}
}
