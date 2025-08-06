/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strncpy.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:38:46 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:38:46 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	while (src[n] != '\0' && n < size)
	{
		dest[n] = src[n];
		n++;
	}
	while (n <= size)
		dest[n++] = '\0';
	return (dest);
}
