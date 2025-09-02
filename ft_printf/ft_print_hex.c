/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:06 by scely             #+#    #+#             */
/*   Updated: 2023/11/28 14:48:16 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int	ft_print_hexa(unsigned int nbr, char c)
{
	char			hexa[20];
	unsigned int	reste;
	unsigned int	i;

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
