/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:44:27 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:44:27 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "includes/solong.h"

void	loop_grave(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game || !game->tomb)
		return ;
	if (game->map->collectibles == 0)
		animate_tomb(param);
}

static void	initialize_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Isometric", true);
	if (!game->mlx)
	{
		perror("Error: mlx_init failed");
		exit(EXIT_FAILURE);
	}
	if (!load_sprites(game->mlx, game->sprites))
	{
		perror("Error: Failed to load sprites");
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
	mlx_resize_image(game->sprites->background, WIDTH, HEIGHT);
	render_map_isometric(game->mlx, *game->sprites, game->map);
}

static void	load_map_and_init(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir archivo");
		exit(1);
	}
	check_dimensions(fd, map);
	close(fd);
	fd = open(filename, O_RDONLY);
	create_map(fd, map);
	close(fd);
	count_elements(map);
	init_enemies(map);
}

static void	initialize_tomb(t_tomb *tomb, mlx_t *mlx)
{
	tomb->x = TOMB_X_POSITION;
	tomb->y = TOMB_Y_POSITION;
	tomb->frame = 0;
	tomb->frame_counter = 0;
	load_tomb_sprites(mlx, tomb);
	initialize_tomb_images(mlx, tomb);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Uso: %s <archivo_mapa>\n", argv[0]);
		return (1);
	}
	init_game(&game);
	load_map_and_init(argv[1], game.map);
	initialize_game(&game);
	initialize_tomb(game.tomb, game.mlx);
	mlx_loop_hook(game.mlx, loop_grave, &game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
