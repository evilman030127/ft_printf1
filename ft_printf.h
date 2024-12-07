/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:53:16 by kakbour           #+#    #+#             */
/*   Updated: 2024/12/07 15:53:51 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

int	ft_putstr(const char *s);
int	ft_putchar(char c);
int	ft_putnbr(long int n);
int	ft_putnbr1(unsigned int n);
int	hexa_convert(unsigned int a, char type);
int	print_adress(unsigned long a);
int	ft_printf(const char *forme, ...);

#endif
