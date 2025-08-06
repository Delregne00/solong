/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 print_str.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 19:04:06 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 19:04:06 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *args)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(*args, char *);
	if (!str)
		str = NULL_STR;
	len = ft_strlen(str);
	if (len < 0)
		return (ERROR);
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) != 1)
			return (ERROR);
		i++;
	}
	return (len);
}
