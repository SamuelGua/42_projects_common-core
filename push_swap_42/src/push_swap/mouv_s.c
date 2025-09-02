/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:46:32 by scely             #+#    #+#             */
/*   Updated: 2024/01/10 15:03:51 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push **pile_A)
{
	t_push	*premier;

	premier = *pile_A;
	if (premier->next == NULL)
		return ;
	(*pile_A) = (*pile_A)->next;
	premier->next = (*pile_A)->next;
	(*pile_A)->next = premier;
	write(1, "sa\n", 3);
}

void	sb(t_push **pile_B)
{
	t_push	*premier;

	premier = *pile_B;
	if (premier->next == NULL)
		return ;
	(*pile_B) = (*pile_B)->next;
	premier->next = (*pile_B)->next;
	(*pile_B)->next = premier;
	write(1, "sb\n", 3);
}

void	ss(t_push **pile_A, t_push **pile_B)
{
	sa(pile_A);
	sb(pile_B);
}
