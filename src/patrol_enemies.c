/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 file3.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:04 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:04 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

void	free_enemies(t_map *map)
{
	if (map->enemy)
	{
		free(map->enemy);
		map->enemy = NULL;
		map->enemies = 0;
	}
}

static void	update_enemy(t_map *map, int i, int next_x, int next_y)
{
	int	curr_x;
	int	curr_y;

	curr_x = map->enemy[i].x;
	curr_y = map->enemy[i].y;
	map->grid[curr_y][curr_x] = '0';
	map->grid[next_y][next_x] = 'e';
	map->enemy[i].x = next_x;
	map->enemy[i].y = next_y;
}

static	void	change_enemy_direction(t_map *map, int i)
{
	int	new_dir;
	int	tried;
	int	next_x;
	int	next_y;

	new_dir = map->enemy[i].current_direction;
	tried = 0;
	while (tried < 4)
	{
		new_dir = (new_dir + 1) % 4;
		if (can_move(map, map->enemy[i].x, map->enemy[i].y, new_dir))
		{
			map->enemy[i].current_direction = new_dir;
			next_x = map->enemy[i].x;
			next_y = map->enemy[i].y;
			get_next_position(new_dir, &next_x, &next_y);
			update_enemy(map, i, next_x, next_y);
			break ;
		}
		tried++;
	}
}

void	patrol_enemies(t_map *map)
{
	int	i;
	int	next_x;
	int	next_y;
	int	direction;

	i = 0;
	while (i < map->enemies)
	{
		direction = map->enemy[i].current_direction;
		if (can_move(map, map->enemy[i].x,
				map->enemy[i].y, direction))
		{
			next_x = map->enemy[i].x;
			next_y = map->enemy[i].y;
			get_next_position(direction, &next_x, &next_y);
			update_enemy(map, i, next_x, next_y);
		}
		else
			change_enemy_direction(map, i);
		i++;
	}
}
