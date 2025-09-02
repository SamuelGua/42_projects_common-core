/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:22:06 by scely             #+#    #+#             */
/*   Updated: 2023/11/28 14:48:25 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_print(int n)
{
	int	a;
	int	b;
	int	counter;

	counter = 0;
	a = n % 10;
	b = n / 10;
	if (b)
		counter += ft_putnbr_print(b);
	if (n < 0)
	{
		if (!b)
		{
			ft_putchar_print('-');
			counter++;
		}
		a = -a;
	}
	ft_putchar_print(a + '0');
	counter++;
	return (counter);
}

int	ft_putnbru_print(unsigned int n)
{
	unsigned int	a;
	unsigned int	b;
	int				counter;

	counter = 0;
	a = n % 10;
	b = n / 10;
	if (b)
		counter += ft_putnbru_print(b);
	if (n < 0)
	{
		if (!b)
		{
			ft_putchar_print('-');
			counter++;
		}
		a = -a;
	}
	ft_putchar_print(a + '0');
	counter++;
	return (counter);
}
