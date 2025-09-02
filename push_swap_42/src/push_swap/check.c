/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:38:14 by scely             #+#    #+#             */
/*   Updated: 2024/01/22 18:20:24 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != 0)
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	len_nbrs(char *nbrs)
{
	long	i;

	i = 0;
	if (nbrs[i] == '-' || nbrs[i] == '+')
		i++;
	while(nbrs[i] == 0)
		i++;
 	if (ft_strlen(&nbrs[i]) > 11)
		return (-1);
	i = ft_atol(nbrs);
	if (i >= -2147483648 && i <= 2147483647)
		return (0);
	else
		return (-1);
}

int	doublons(t_push **pileA)
{
	t_push	*temp_a;
	t_push	*temp_b;

	temp_a = (*pileA);
	temp_b = (*pileA)->next;
	while (temp_a->next != NULL)
	{
		temp_b = temp_a->next;
		while (temp_b != NULL)
		{
			if (temp_a->content == temp_b->content)
				return (-1);
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	return (0);
}
