/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_itoa.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 20:04:23 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 20:04:23 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	fill_number(char *result, int n, int length, int is_negative)
{
	result[length] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		result[--length] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		result[0] = '-';
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = count_digits(n);
	result = (char *)malloc(length + 1);
	if (!result)
		return (NULL);
	is_negative = (n < 0);
	if (is_negative)
		n = -n;
	fill_number(result, n, length, is_negative);
	return (result);
}
