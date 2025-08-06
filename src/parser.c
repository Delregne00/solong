/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 parser.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:46 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:46 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	flood_fill(t_map *map, char **visited, int x, int y)
{
	if (check_move(map, x, y) || visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	flood_fill(map, visited, x + 1, y);
	flood_fill(map, visited, x - 1, y);
	flood_fill(map, visited, x, y + 1);
	flood_fill(map, visited, x, y - 1);
}

static char	**create_visited_array(t_map *map)
{
	char	**visited;
	int		i;

	visited = (char **)malloc(sizeof(char *) * map->rows);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < map->rows)
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
		i++;
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

static int	validate_map_cells(t_map *map, char **visited)
{
	int	i;
	int	j;
	int	valid;

	valid = 1;
	i = -1;
	while (++i < map->rows && valid)
	{
		j = -1;
		while (++j < map->cols && valid)
			if ((map->grid[i][j] == 'C' || map->grid[i][j] == 'E') &&
				visited[i][j] != '1')
				valid = 0;
	}
	if (!valid)
		perror("Hay coleccionables o puerta inaccesibles en el mapa");
	return (valid);
}

int	check_map_accessibility(t_map *map)
{
	char	**visited;
	int		valid;

	visited = create_visited_array(map);
	if (!visited)
	{
		perror("Error al crear array de visitados");
		return (0);
	}
	flood_fill(map, visited, map->player_x, map->player_y);
	valid = validate_map_cells(map, visited);
	free_visited(visited, map->rows);
	return (valid);
}
