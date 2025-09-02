/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:46:30 by scely             #+#    #+#             */
/*   Updated: 2024/01/23 14:03:03 by meca_971         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push **pile_A, t_push **pile_B)
{
	t_push	*temp;

	if ((*pile_B) == NULL)
		return ;
	temp = (*pile_B)->next;
	(*pile_B)->next = *pile_A;
	(*pile_A) = (*pile_B);
	*pile_B = temp;
	write(1, "pa\n", 3);
}

void	pb(t_push **pile_A, t_push **pile_B)
{
	t_push	*temp;

	if ((*pile_A) == NULL)
		return ;
	temp = (*pile_A)->next;
	(*pile_A)->next = *pile_B;
	(*pile_B) = (*pile_A);
	*pile_A = temp;
	write(1, "pb\n", 3);
}
