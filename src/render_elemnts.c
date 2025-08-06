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

void	render_background(mlx_t *mlx, t_sprites sprites)
{
	mlx_image_to_window(mlx, sprites.background, 0, 0);
	mlx_image_to_window(mlx, sprites.moon, 600, -2200);
}

void	render_player(mlx_t *mlx, t_sprites sprites, t_iso_coords pos)
{
	if (sprites.person)
		mlx_image_to_window(mlx, sprites.person, pos.x, pos.wall);
	else
		mlx_image_to_window(mlx, sprites.person_flip, pos.x, pos.wall);
}

void	render_brick(mlx_t *mlx, t_sprites sprites, t_iso_coords pos)
{
	mlx_image_to_window(mlx, sprites.brick, pos.x, pos.y);
	mlx_image_to_window(mlx, sprites.brick, pos.x, pos.y - TILE_HEIGHT / 4);
}
