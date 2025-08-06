/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 parser_2.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:56 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:56 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_map_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (map->grid[0][i] != '1' || map->grid[map->rows - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->cols - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	**init_visited(t_map *map)
{
	char	**visited;
	int		i;

	visited = (char **)malloc(sizeof(char *) * map->rows);
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < map->rows)
	{
		visited[i] = (char *)malloc(sizeof(char) * map->cols);
		if (!visited[i])
		{
			while (i > 0)
				free(visited[--i]);
			free(visited);
			return (NULL);
		}
		ft_memset(visited[i], '0', map->cols);
	}
	return (visited);
}

static void	free_visited(char **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(visited[i++]);
	free(visited);
}

static void	flood_fill(t_map *map, char **visited, int x, int y)
{
	if (x < 0 || x >= map->cols || y < 0 || y >= map->rows
		|| map->grid[y][x] == '1' || visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	flood_fill(map, visited, x + 1, y);
	flood_fill(map, visited, x - 1, y);
	flood_fill(map, visited, x, y + 1);
	flood_fill(map, visited, x, y - 1);
}

int	check_map_accessibility(t_map *map)
{
	char	**visited;
	int		i;
	int		j;
	int		valid;

	visited = init_visited(map);
	if (!visited)
	{
		perror("Error al crear array de visitados");
		return (0);
	}
	flood_fill(map, visited, map->player_x, map->player_y);
	valid = 1;
	i = -1;
	while (++i < map->rows && valid)
	{
		j = -1;
		while (++j < map->cols && valid)
			if ((map->grid[i][j] == 'C' || map->grid[i][j] == 'e')
				&& visited[i][j] != '1')
				valid = 0;
	}
	free_visited(visited, map->rows);
	return (valid);
}
