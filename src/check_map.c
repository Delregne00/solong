/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 parser_1.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/21 09:43:51 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/02/21 09:43:51 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	validate_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != 'C' && line[i] != 'P'
			&& line[i] != '0' && line[i] != 'e' && line[i] != 'E'
			&& line[i] != '\n')
		{
			perror("Caracter no admitido en el mapa");
			exit(1);
		}
		i++;
	}
	return (i);
}

static void	count_map_items(t_map *map, int *player_count)
{
	int	i;
	int	j;

	*player_count = 0;
	map->collectibles = 0;
	map->enemies = 0;
	map->exit = 0;
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->grid[i][j] == 'P')
			{
				(*player_count)++;
				map->player_x = j;
				map->player_y = i;
			}
			else if (map->grid[i][j] == 'C')
				map->collectibles++;
			else if (map->grid[i][j] == 'E')
				map->exit++;
		}
	}
}

void	count_elements(t_map *map)
{
	int	player_count;

	count_map_items(map, &player_count);
	if (player_count != 1)
	{
		perror("Error: El mapa debe contener exactamente un jugador");
		exit(1);
	}
	if (!check_map_accessibility(map))
	{
		perror("Error: El mapa no es accesible");
		exit(1);
	}
	if (!check_map_borders(map))
	{
		perror("Error: El mapa no tiene bordes válidos");
		exit(1);
	}
	if (map->collectibles == 0 || map->exit == 0)
	{
		perror("Error: El mapa debe contener una coleccion y una salida");
		exit(1);
	}
}

void	create_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	map->grid = (char **)malloc(sizeof(char *) * map->rows);
	if (!map->grid)
	{
		perror("Error al asignar memoria para el mapa");
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->grid[i] = (char *)malloc(sizeof(char) * (map->cols + 1));
		if (!map->grid[i])
		{
			perror("Error al asignar memoria para una fila");
			exit(1);
		}
		ft_strlcpy(map->grid[i], line, map->cols + 1);
		free(line);
		i++;
		line = get_next_line(fd);
	}
}

void	check_dimensions(int fd, t_map *map)
{
	char	*line;
	int		first_len;
	int		curr_len;

	first_len = -2;
	map->rows = 0;
	map->cols = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		curr_len = validate_line(line);
		if (first_len == -2)
			first_len = curr_len;
		else if (curr_len != first_len)
		{
			perror("El mapa no tiene filas del mismo tamaño");
			exit(1);
		}
		map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	map->cols = first_len;
}
