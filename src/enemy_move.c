/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 file3_1.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:09 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:09 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

int	can_move(t_map *map, int x, int y, int direction)
{
	if (direction == NORTH && y > 0 && map->grid[y - 1][x] == '0')
		return (1);
	if (direction == WEST && x > 0 && map->grid[y][x - 1] == '0')
		return (1);
	if (direction == SOUTH && y < map->rows - 1 && map->grid[y + 1][x] == '0')
		return (1);
	if (direction == EAST && x < map->cols - 1 && map->grid[y][x + 1] == '0')
		return (1);
	return (0);
}

void	get_next_position(int direction, int *x, int *y)
{
	if (direction == NORTH)
		(*y)--;
	else if (direction == WEST)
		(*x)--;
	else if (direction == SOUTH)
		(*y)++;
	else if (direction == EAST)
		(*x)++;
}
