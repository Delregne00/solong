/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strdup.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:38:20 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:38:20 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	char	*strdup;
	int		size;

	size = ft_strlen(s1);
	arr = malloc((size + 1) * sizeof(char));
	if (!arr)
		return (0);
	strdup = arr;
	while (*s1)
	{
		*arr = *s1;
		arr++;
		s1++;
	}
	*arr = '\0';
	return (strdup);
}
