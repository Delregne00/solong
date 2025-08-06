/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_bzero.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:37:07 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:37:07 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char			*char_s;
	unsigned int	c;

	c = 0;
	char_s = (char *)s;
	while (c < n)
	{
		*char_s = '\0';
		char_s++;
		c++;
	}
	return (s);
}
