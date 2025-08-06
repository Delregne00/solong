/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf.h										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/29 18:41:30 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/29 18:41:30 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1
# define HEX_BASE "0123456789abcdef"
# define HEX_UP_BASE "0123456789ABCDEF"
# define HEX_PREFIX "0x"
# define NULL_STR "(null)"
# define NIL_PTR "(nil)"
# define LOWER 0
# define UPPER 1

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list *args);
int		ft_print_str(va_list *args);
int		ft_print_int(va_list *args);
int		ft_print_uint(va_list *args);
int		ft_print_hex(va_list *args, int uppercase);
int		ft_print_pointer(va_list *args);
int		ft_print_percent(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);
int		count_digits_base(unsigned long n, int base);

#endif
