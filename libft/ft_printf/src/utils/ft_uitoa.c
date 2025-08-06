/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_uitoa.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 20:22:07 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 20:22:07 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char			*arr;
	unsigned int	temp;
	int				length;

	if (n == 0)
		return (ft_strdup("0"));
	temp = n;
	length = 0;
	while (temp != 0)
	{
		temp /= 10;
		length++;
	}
	arr = malloc((length + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[length] = '\0';
	while (n > 0)
	{
		arr[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (arr);
}
