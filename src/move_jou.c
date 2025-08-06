/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 file5.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:23 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:23 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_move(t_map *map, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= map->cols)
		return (0);
	if (new_y < 0 || new_y >= map->rows)
		return (0);
	return (is_valid_position(map->grid[new_y][new_x]));
}

void	move_person(t_game *game)
{
	int			new_x;
	int			new_y;

	new_x = game->map->player_x + game->dx;
	new_y = game->map->player_y + game->dy;
	if (!check_move(game->map, new_x, new_y))
		return ;
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	update_move_counter(game->mlx, game->move_count);
	update_player_position(game->map, new_x, new_y);
	finish_move_process(game);
}

void	update_move_counter(mlx_t *mlx, int move_count)
{
	static mlx_image_t	*counter = NULL;
	char				*str;

	if (counter)
		mlx_delete_image(mlx, counter);
	str = ft_itoa(move_count);
	counter = mlx_put_string(mlx, str, 1150, 350);
	free(str);
}

int	is_valid_position(char cell_type)
{
	if (cell_type == '1' || cell_type == 'E')
		return (0);
	return (1);
}
