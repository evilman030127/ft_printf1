/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:51:52 by kakbour           #+#    #+#             */
/*   Updated: 2024/12/07 15:51:56 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(long int n)
{
	int		i;
	int		j;
	char	s[10];

	j = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		n = -n;
		j = ft_putchar('-');
	}
	while (n >= 10)
	{
		s[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (n >= 0 && n <= 9)
		j += ft_putchar(n + 48);
	j += i;
	while (i > 0)
		ft_putchar(s[--i]);
	return (j);
}

int	ft_putnbr1(unsigned int n)
{
	int		i;
	int		j;
	char	s[10];

	i = 0;
	if (n == 0)
		return (write (1, &"0", 1));
	while (n)
	{
		s[i++] = (n % 10) + 48;
		n = n / 10;
	}
	j = i;
	while (i > 0)
		ft_putchar(s[--i]);
	return (j);
}

int	hexa_convert(unsigned int a, char type)
{
	char	*base;
	char	s[20];
	int		i;
	int		j;
	int		r;

	i = 0;
	if (a == 0)
		return (write (1, &"0", 1));
	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (a > 0)
	{
		r = a % 16;
		if (r >= 0 && r <= 16)
			s[i++] = base[r];
		a = a / 16;
	}
	j = i;
	while (i > 0)
		ft_putchar(s[--i]);
	return (j);
}
