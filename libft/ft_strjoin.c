/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strjoin.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:38:28 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:38:28 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		n;
	int		total_size;

	if (!s1 || !s2)
		return ((void *) 0);
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(total_size * sizeof(char));
	if (!join)
		return (NULL);
	n = 0;
	while (s1[n] != '\0')
	{
		join[n] = s1[n];
		n++;
	}
	while (*s2)
	{
		join[n] = *s2;
		n++;
		s2++;
	}
	join[n] = '\0';
	return (join);
}
