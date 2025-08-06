/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strdup.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 20:19:43 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 20:19:43 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	char	*strdup;

	arr = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
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
