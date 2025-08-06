/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 print_int.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 19:00:48 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 19:00:48 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *args)
{
	int		nb;
	char	*str;
	int		len;

	nb = va_arg(*args, int);
	str = ft_itoa(nb);
	if (!str)
		return (ERROR);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
