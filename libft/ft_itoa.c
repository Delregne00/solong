/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_itoa.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/09/25 12:37:37 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/09/25 12:37:37 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

static char	*reverse_string(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

static char	*int_to_str(int n, char *arr, int is_negative)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		arr[i++] = '0';
		arr[i] = '\0';
		return (arr);
	}
	while (n > 0)
	{
		arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		arr[i++] = '-';
	arr[i] = '\0';
	return (reverse_string(arr));
}

static int	count_numbers(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	arr = malloc((count_numbers(n) + is_negative + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	return (int_to_str(n, arr, is_negative));
}
