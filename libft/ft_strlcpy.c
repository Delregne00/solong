/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strlcpy.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:38:35 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:38:35 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	if (dstsize == 0)
	{
		while (src[src_len] != '\0')
			src_len++;
		return (src_len);
	}
	while (src[src_len] != '\0' && src_len < dstsize - 1)
	{
		dst[src_len] = src[src_len];
		src_len++;
	}
	dst[src_len] = '\0';
	return (ft_strlen(src));
}
