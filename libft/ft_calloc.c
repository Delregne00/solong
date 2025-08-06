/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_calloc.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:37:11 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:37:11 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t	size)
{
	void	*ptr;
	int		total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return ((void *) 0);
	return (ft_memset(ptr, 0, total_size));
}
