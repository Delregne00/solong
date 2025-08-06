/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_memchr.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:37:40 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:37:40 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*char_s;
	char	char_c;

	char_s = (char *)s;
	char_c = (char) c;
	while (n-- > 0)
	{
		if (*char_s == char_c)
			return ((void *)char_s);
		char_s++;
	}
	return ((void *) 0);
}
