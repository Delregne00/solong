/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_memset.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:37:53 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:37:53 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*char_b;
	char	char_c;

	char_b = (char *)b;
	char_c = (char)c;
	while (len > 0)
	{
		*char_b = char_c;
		char_b++;
		len--;
	}
	return (b);
}
