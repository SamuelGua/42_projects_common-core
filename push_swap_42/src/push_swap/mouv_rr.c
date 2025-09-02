/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:49:02 by scely             #+#    #+#             */
/*   Updated: 2024/01/24 13:36:58 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push **pile_A)
{
	t_push	*temp;
	t_push	*lst;

	if ((*pile_A)->next == NULL)
		return ;
	temp = (*pile_A);
	while ((*pile_A)->next != NULL)
	{
		lst = (*pile_A);
		(*pile_A) = (*pile_A)->next;
	}
	lst->next = NULL;
	(*pile_A)->next = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_push **pile_b)
{
	t_push	*temp;
	t_push	*lst;

	if ((*pile_b)->next == NULL)
		return ;
	temp = (*pile_b);
	while ((*pile_b)->next != NULL)
	{
		lst = (*pile_b);
		(*pile_b) = (*pile_b)->next;
	}
	lst->next = NULL;
	(*pile_b)->next = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_push **pile_A, t_push **pile_B)
{
	t_push	*temp;
	t_push	*lst;

	if ((*pile_A)->next == NULL)
		return ;
	temp = (*pile_A);
	while ((*pile_A)->next != NULL)
	{
		lst = (*pile_A);
		(*pile_A) = (*pile_A)->next;
	}
	lst->next = NULL;
	(*pile_A)->next = temp;
	if ((*pile_B)->next == NULL)
		return ;
	temp = (*pile_B);
	while ((*pile_B)->next != NULL)
	{
		lst = (*pile_B);
		(*pile_B) = (*pile_B)->next;
	}
	lst->next = NULL;
	(*pile_B)->next = temp;
	write(1, "rrr\n", 4);
}
