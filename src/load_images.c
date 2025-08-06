/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 load_images.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:32 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:32 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

mlx_image_t	*load_image(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		perror("Error: Failed to load texture");
		return (NULL);
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		perror("Error: texture to image");
		return (NULL);
	}
	return (image);
}

bool	load_sprites(mlx_t *mlx, t_sprites *sprites)
{
	sprites->background = load_image(mlx, "./textures/background.png");
	sprites->brick = load_image(mlx, "./textures/brick1.png");
	sprites->person = load_image(mlx, "./textures/person6.png");
	sprites->person_flip = load_image(mlx, "./textures/person_flip.png");
	sprites->enemy = load_image(mlx, "./textures/enemy.png");
	sprites->floor = load_image(mlx, "./textures/floor_00.png");
	sprites->succes = load_image(mlx, "./textures/success.png");
	sprites->death = load_image(mlx, "./textures/death.png");
	sprites->cloud = load_image(mlx, "./textures/book2.png");
	sprites->moon = load_image(mlx, "./textures/moon.png");
	sprites->cloud_1 = load_image(mlx, "./textures/book3.png");
	sprites->wall = load_image(mlx, "./textures/floor_01.png");
	sprites->special_object = load_image(mlx, "./textures/tomb.png");
	return (true);
}
