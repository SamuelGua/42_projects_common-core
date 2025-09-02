/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:48 by scely             #+#    #+#             */
/*   Updated: 2023/11/28 14:48:29 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa(char *hexa)
{
	unsigned int	i;

	i = ft_strlen(hexa);
	while (i > 0)
	{
		ft_putchar_print(hexa[i - 1]);
		i--;
	}
	return (ft_strlen(hexa));
}

int	ft_print_hexa_ptr(unsigned long int nbr, char c)
{
	char				hexa[20];
	unsigned long int	reste;
	unsigned long int	i;

	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr != 0)
	{
		reste = nbr % 16;
		if (reste < 10)
			hexa[i] = reste + '0';
		else if (c == 'X')
			hexa[i] = reste + '7';
		else if (c == 'x')
			hexa[i] = reste + 'W';
		nbr /= 16;
		i++;
	}
	hexa[i] = '\0';
	i = ft_hexa(hexa);
	return (i);
}

int	ft_print_ptr(void *p)
{
	unsigned long int	i;
	int					c;

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = (unsigned long int)p;
	write(1, "0x", 2);
	c = ft_print_hexa_ptr(i, 'x') + 2;
	return (c);
}
