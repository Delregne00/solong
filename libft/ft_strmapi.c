/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strmapi.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:41:47 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:41:47 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;

	i = 0;
	if (!s || !f)
		return (NULL);
	arr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
