/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_split.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:36:55 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:36:55 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**free_split(char **split, int i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
	return (NULL);
}

static char	**put_words(const char *s, char c, char **split)
{
	size_t	end;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			end = 0;
			while (s[end] && s[end] != c)
				end++;
			split[i] = ft_strndup(s, end);
			if (!split[i])
				return (free_split(split, i));
			i++;
			s += end;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (put_words(s, c, split));
}
