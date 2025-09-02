/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:07:47 by scely             #+#    #+#             */
/*   Updated: 2023/11/28 14:52:43 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formats(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == '%')
		i = ft_putchar_print('%');
	else if (c == 'd' || c == 'i')
		i = ft_putnbr_print(va_arg(args, int));
	else if (c == 'u')
		i = ft_putnbru_print(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr_print(va_arg(args, char *));
	else if (c == 'c')
		i = ft_putchar_print((char)va_arg(args, int));
	else if (c == 'x' || c == 'X')
		i = ft_print_hexa(va_arg(args, unsigned int), c);
	else if (c == 'p')
		i = ft_print_ptr(va_arg(args, void *));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		k;
	va_list	args;

	i = 0;
	k = 0;
	if (!str)
		return (-1);
	va_start (args, str);
	while (str[i] && i < (int )ft_strlen(str))
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar_print(str[i++]);
			k++;
		}
		i++;
		if (str[i - 1] == '%' && str[i] != 0)
		{
			k += formats(args, str[i]);
			i++;
		}				
	}
	return (k);
}
