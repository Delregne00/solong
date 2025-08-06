/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 file2.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:42:57 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:42:57 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	count_map_enemies(t_map *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'e')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	fill_enemies_data(t_map *map)
{
	int	idx;
	int	x;
	int	y;

	idx = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'e')
			{
				map->enemy[idx].x = x;
				map->enemy[idx].y = y;
				map->enemy[idx].current_direction = rand() % 4;
				idx++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_map *map)
{
	map->enemies = count_map_enemies(map);
	map->enemy = malloc(map->enemies * sizeof(t_enemy));
	if (!map->enemy)
	{
		ft_printf("Error: No se pudo asignar memoria para los enemigos\n");
		return ;
	}
	fill_enemies_data(map);
}
