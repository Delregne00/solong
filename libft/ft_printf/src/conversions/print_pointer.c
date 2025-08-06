/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 print_pointer.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 19:03:05 by acarranz			#+#    #+#			 */
/*	 Updated: 2024/10/29 19:03:05 by acarranz		   ###	 ########.fr	 */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += put_hex(n / 16);
	if (write(1, &HEX_BASE[n % 16], 1) != 1)
		return (ERROR);
	return (len + 1);
}

static int	print_hex_addr(unsigned long addr)
{
	int		len;
	ssize_t	written;

	len = 0;
	written = write(1, HEX_PREFIX, ft_strlen(HEX_PREFIX));
	if (written != (ssize_t)ft_strlen(HEX_PREFIX))
		return (ERROR);
	len = put_hex(addr);
	if (len == ERROR)
		return (ERROR);
	return (len + ft_strlen(HEX_PREFIX));
}

int	ft_print_pointer(va_list *args)
{
	void			*ptr;
	unsigned long	addr;
	ssize_t			result;

	ptr = va_arg(*args, void *);
	if (!ptr)
	{
		result = write(1, NIL_PTR, ft_strlen(NIL_PTR));
		if (result != (ssize_t)ft_strlen(NIL_PTR))
			return (ERROR);
		return (result);
	}
	addr = (unsigned long)ptr;
	return (print_hex_addr(addr));
}
