/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 18:46:27 by acarranz			#+#    #+#			 */
/*	 Updated: 2024/10/29 18:46:27 by acarranz		   ###	 ########.fr	 */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

static int	control_type(char type, va_list *args)
{
	int	result;

	result = 0;
	if (type == 'c')
		result = ft_print_char(args);
	else if (type == 's')
		result = ft_print_str(args);
	else if (type == 'd' || type == 'i')
		result = ft_print_int(args);
	else if (type == 'u')
		result = ft_print_uint(args);
	else if (type == 'x')
		result = ft_print_hex(args, LOWER);
	else if (type == 'X')
		result = ft_print_hex(args, UPPER);
	else if (type == 'p')
		result = ft_print_pointer(args);
	else if (type == '%')
		result = ft_print_percent();
	return (result);
}

static int	process_format(const char **format, va_list *args)
{
	int	result;

	if (**format == '%')
	{
		(*format)++;
		if (**format)
		{
			result = control_type(**format, args);
			if (result == ERROR)
				return (ERROR);
			(*format)++;
			return (result);
		}
	}
	if (write(1, *format, 1) != 1)
		return (ERROR);
	(*format)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		result;

	if (!format)
		return (ERROR);
	total = 0;
	va_start(args, format);
	while (*format)
	{
		result = process_format(&format, &args);
		if (result == ERROR)
		{
			va_end(args);
			return (ERROR);
		}
		total += result;
	}
	va_end(args);
	return (total);
}
