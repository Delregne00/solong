/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_memcpy.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:37:47 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:37:47 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*char_d;
	char	*char_s;
	size_t	i;

	if (!dest && !src)
		return ((void *) 0);
	char_d = (char *)dest;
	char_s = (char *)src;
	i = 0;
	while (i < n)
	{
		char_d[i] = char_s[i];
		i++;
	}
	return (dest);
}
