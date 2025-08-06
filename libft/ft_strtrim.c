/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strtrim.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:38:55 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:38:55 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*strtrimcpy(const char *s1, char *str, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (i < (end - start))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[end - start] = '\0';
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	char	*empty_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	if (start >= end)
	{
		empty_str = (char *)malloc(1);
		if (!empty_str)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	return (strtrimcpy(s1, str, start, end));
}
