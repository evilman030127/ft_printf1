/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:50 by kakbour           #+#    #+#             */
/*   Updated: 2024/12/07 15:45:00 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_adress(unsigned long a)
{
	char	*base;
	char	s[20];
	int		i;
	int		j;
	long	r;

	i = 0;
	base = "0123456789abcdef";
	if (a == 0)
	{
		return (write (1, &"(nil)", 5));
	}
	j = write(1, "0x", 2);
	while (a > 0)
	{
		r = a % 16;
		if (r >= 0 && r <= 16)
			s[i++] = base[r];
		a = a / 16;
	}
	j += i;
	while (i > 0)
		ft_putchar(s[--i]);
	return (j);
}

int	write_things(va_list args, const char *format)
{
	int	count;

	count = 0;
	if (format == NULL)
		return (-1);
	if (*format == 'c')
		count = ft_putchar(va_arg(args, int)) - 2;
	else if (*format == 's')
		count = ft_putstr(va_arg(args, const char *)) - 2;
	else if (*format == 'd' || *format == 'i')
		count = ft_putnbr(va_arg(args, int)) - 2;
	else if (*format == 'u')
		count = ft_putnbr1(va_arg(args, int)) - 2;
	else if (*format == '%')
		count = write(1, &(*format), 1) - 2;
	else if (*format == 'x' || *format == 'X')
		count = hexa_convert(va_arg(args, int), format[0]) - 2;
	else if (*format == 'p')
		count = print_adress(va_arg(args, unsigned long)) - 2;
	return (count);
}

int	ft_printf(const char *forme, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start (args, forme);
	i = 0;
	j = 0;
	while (forme[i])
	{
		if (forme[i] != '%')
			write(1, &forme[i], 1);
		else if (forme[i] == '%')
			j += write_things(args, forme + ((i++) + 1));
		i++;
	}
	va_end (args);
	return (i + j);
}
