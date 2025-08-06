/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 print_uint.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 19:06:35 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 19:06:35 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list *args)
{
	unsigned int	nb;
	char			*str;
	int				len;

	nb = va_arg(*args, unsigned int);
	str = ft_uitoa(nb);
	if (!str)
		return (ERROR);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
