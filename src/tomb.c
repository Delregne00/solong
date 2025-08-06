/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 tomb.c												:+:		 :+:	:+*/
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:47:22 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:47:22 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_single_tomb_sprite(mlx_t *mlx, int i, t_tomb *tomb)
{
	char			path[50];
	mlx_texture_t	*texture;

	snprintf(path, sizeof(path), "textures/%d.png", i + 1);
	texture = mlx_load_png(path);
	tomb->images[i] = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(tomb->images[i], tomb->images[i]->width * TOMB_SCALE,
		tomb->images[i]->height * TOMB_SCALE);
	mlx_delete_texture(texture);
	tomb->images[i]->enabled = false;
}

void	load_tomb_sprites(mlx_t *mlx, t_tomb *tomb)
{
	int	i;

	i = 0;
	while (i < TOMB_SPRITES)
	{
		load_single_tomb_sprite(mlx, i, tomb);
		i++;
	}
}

void	initialize_tomb_images(mlx_t *mlx, t_tomb *tomb)
{
	int	i;

	i = 0;
	while (i < TOMB_SPRITES)
	{
		mlx_image_to_window(mlx, tomb->images[i], tomb->x, tomb->y);
		tomb->images[i]->enabled = false;
		i++;
	}
	tomb->images[tomb->frame]->enabled = true;
}

void	update_tomb_frame(t_tomb *tomb)
{
	static int	prev_frame;

	prev_frame = 0;
	tomb->frame_counter++;
	if (tomb->frame_counter >= TOMB_FRAME_DELAY)
	{
		tomb->images[prev_frame]->enabled = false;
		tomb->frame = (tomb->frame + 1) % TOMB_SPRITES;
		tomb->images[tomb->frame]->enabled = true;
		tomb->frame_counter = 0;
	}
	prev_frame = tomb->frame;
}

void	animate_tomb(void *param)
{
	static bool	first_render = true;
	t_game		*game;

	game = (t_game *)param;
	if (!game || !game->tomb || !game->map)
		return ;
	if (game->map->collectibles != 0)
		return ;
	if (first_render)
	{
		game->tomb->x = TOMB_X_POSITION;
		game->tomb->y = TOMB_Y_POSITION;
		game->tomb->frame = 0;
		game->tomb->frame_counter = 0;
		first_render = false;
		return ;
	}
	update_tomb_frame(game->tomb);
}
