/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 print_char.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 18:57:28 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 18:57:28 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	char	chr;

	chr = (char)va_arg(*args, int);
	if (write(1, &chr, 1) != 1)
		return (ERROR);
	return (1);
}
