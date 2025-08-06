/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 utils.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:44:19 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:44:19 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

t_iso_coords	cart_to_iso(int x, int y)
{
	t_iso_coords	iso;

	iso.x = (x - y) * (TILE_WIDTH / 2) + OFFSET_X;
	iso.y = (x + y) * (TILE_HEIGHT / 3.5) + OFFSET_Y;
	iso.wall = iso.y + TILE_HEIGHT / 2;
	iso.moviments = 0;
	return (iso);
}

void	clear_window(mlx_t *mlx, t_sprites sprites)
{
	mlx_delete_image(mlx, sprites.floor);
	mlx_delete_image(mlx, sprites.wall);
	mlx_delete_image(mlx, sprites.cloud);
	mlx_delete_image(mlx, sprites.background);
	mlx_delete_image(mlx, sprites.person);
}
