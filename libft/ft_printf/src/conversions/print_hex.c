/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 print_hex.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 18:59:21 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 18:59:21 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(va_list *args, int uppercase)
{
	unsigned int	num;
	char			*hex_chars;
	char			hex_buffer[16];
	int				len;
	int				i;

	num = va_arg(*args, unsigned int);
	len = 0;
	i = 0;
	if (uppercase)
		hex_chars = HEX_UP_BASE;
	else
		hex_chars = HEX_BASE;
	if (num == 0)
		return (write(1, "0", 1));
	while (num > 0)
	{
		hex_buffer[i++] = hex_chars[num % 16];
		num /= 16;
	}
	while (i--)
		len += write(1, &hex_buffer[i], 1);
	return (len);
}
