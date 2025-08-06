/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 init_end.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/23 12:33:07 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/23 12:33:07 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	game->sprites = malloc(sizeof(t_sprites));
	game->tomb = malloc(sizeof(t_tomb));
	game->pos = malloc(sizeof(t_iso_coords));
	if (!game->map || !game->sprites || !game->tomb || !game->pos)
	{
		cleanup_game(game);
		perror("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	ft_memset(game->map, 0, sizeof(t_map));
	ft_memset(game->sprites, 0, sizeof(t_sprites));
	ft_memset(game->tomb, 0, sizeof(t_tomb));
	ft_memset(game->pos, 0, sizeof(t_iso_coords));
	game->move_count = 0;
	game->death = 0;
	game->succes = 0;
	game->dx = 0;
	game->dy = 0;
	game->person_direction = 0;
	game->get_collect = 0;
}

void	free_map_grid(char **grid, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		if (game->sprites)
			delete_images(game->mlx, game->sprites);
		mlx_terminate(game->mlx);
	}
	if (game->map)
	{
		free_enemies(game->map);
		if (game->map->grid)
			free_map_grid(game->map->grid, game->map->rows);
		free(game->map);
	}
	free(game->moves_str);
	free(game->sprites);
	free(game->tomb);
	free(game->pos);
	ft_memset(game, 0, sizeof(t_game));
}
