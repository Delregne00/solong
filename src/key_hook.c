/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 file6.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:27 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:27 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

void	set_move_params(t_game *game, int key)
{
	if (key == MLX_KEY_W)
	{
		game->person_direction = 1;
		game->dx = 0;
		game->dy = -1;
	}
	else if (key == MLX_KEY_S)
	{
		game->person_direction = 2;
		game->dx = 0;
		game->dy = 1;
	}
	else if (key == MLX_KEY_A)
	{
		game->person_direction = 3;
		game->dx = -1;
		game->dy = 0;
	}
	else if (key == MLX_KEY_D)
	{
		game->person_direction = 4;
		game->dx = 1;
		game->dy = 0;
	}
}

void	handle_key_press(t_game *game, int key)
{
	if (key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		if (game->death == 1)
			ft_printf("¡Has perdido!\n");
		else if (game->succes == 1)
			ft_printf("¡Has ganado!\n");
		else
			ft_printf("¡Has salido del juego!\n");
		exit(0);
	}
	if (game->death == 0 && game->succes == 0
		&& (key == MLX_KEY_W || key == MLX_KEY_A
			|| key == MLX_KEY_S || key == MLX_KEY_D))
	{
		set_move_params(game, key);
		move_person(game);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	handle_key_press(game, keydata.key);
}
