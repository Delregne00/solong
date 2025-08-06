/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 render.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:44:03 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:44:03 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	content(mlx_t *mlx, t_sprites sprites, t_iso_coords pos, char cell)
{
	if (cell == '0' || cell == '1' || cell == 'P' || cell == 'E'
		|| cell == 'C' || cell == 'e' || cell == 'W')
		mlx_image_to_window(mlx, sprites.wall, pos.x, pos.wall);
	if (cell == 'P')
		render_player(mlx, sprites, pos);
	if (cell == 'e')
		mlx_image_to_window(mlx, sprites.enemy, pos.x, pos.wall);
	if (cell == 'C')
		mlx_image_to_window(mlx, sprites.cloud, pos.x,
			pos.wall - TILE_HEIGHT / 8);
	if (cell == 'D')
		mlx_image_to_window(mlx, sprites.special_object, pos.x, pos.wall);
	if (cell == '1')
		render_brick(mlx, sprites, pos);
}

static	void	render_row(mlx_t *mlx, t_sprites sprites, t_map *map, int y)
{
	int				x;
	t_iso_coords	pos;
	char			cell;

	x = 0;
	while (x < map->cols)
	{
		pos = cart_to_iso(x, y);
		cell = map->grid[y][x];
		content(mlx, sprites, pos, cell);
		x++;
	}
}

void	render_map_isometric(mlx_t *mlx, t_sprites sprites, t_map *map)
{
	int	y;

	y = 0;
	if (!mlx || !map || !map->grid)
	{
		ft_printf("Error: Invalid parameters in render_map_isometric\n");
		exit(1);
	}
	if (map->rows <= 0 || map->cols <= 0)
	{
		ft_printf("Error: Invalid map dimensions\n");
		exit(1);
	}
	if (!sprites.background)
	{
		ft_printf("Error: Background sprite not loaded\n");
		exit(1);
	}
	render_background(mlx, sprites);
	while (y < map->rows)
	{
		render_row(mlx, sprites, map, y);
		y++;
	}
}
