/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/31 20:31:00 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/31 20:31:00 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

static int	find_newline(char *buf, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static ssize_t	read_from_file(int fd, t_buf *data)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, data->sub_buf, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		data->sub_buf[bytes_read] = '\0';
		data->available = bytes_read;
		data->ptr = data->sub_buf;
	}
	return (bytes_read);
}

static void	process_buffer(char **line, t_buf *data, int *newline_index)
{
	char	*temp;

	*newline_index = find_newline(data->ptr, data->available);
	if (*newline_index >= 0)
	{
		temp = ft_strndup_get(data->ptr, *newline_index + 1);
		*line = ft_strjoin_and_free(*line, temp);
		free(temp);
		data->ptr += *newline_index + 1;
		data->available -= *newline_index + 1;
	}
	else
	{
		*line = ft_strjoin_and_free(*line, data->ptr);
		data->available = 0;
		data->ptr = NULL;
	}
}

static char	*handle_read(int fd, t_buf *data)
{
	char	*line;
	ssize_t	bytes_read;
	int		newline_index;

	line = NULL;
	while (1)
	{
		if (data->available == 0)
		{
			bytes_read = read_from_file(fd, data);
			if (bytes_read < 0)
			{
				free(line);
				free(data->sub_buf);
				data->sub_buf = NULL;
				return (NULL);
			}
			if (bytes_read == 0)
				break ;
		}
		process_buffer(&line, data, &newline_index);
		if (newline_index >= 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buf	buffers[FD_SETSIZE];
	t_buf			*data;
	char			*line;

	data = &buffers[fd];
	line = NULL;
	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (data->sub_buf == NULL)
	{
		data->sub_buf = malloc(BUFFER_SIZE + 1);
		if (data->sub_buf == NULL)
			return (NULL);
	}
	line = handle_read(fd, data);
	if (line == NULL && data->available == 0)
	{
		free(data->sub_buf);
		data->sub_buf = NULL;
	}
	return (line);
}
