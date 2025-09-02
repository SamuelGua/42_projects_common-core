/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:06:17 by meca_971          #+#    #+#             */
/*   Updated: 2024/01/24 15:02:38 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_param(t_push **pile)
{
	t_push	*temp;

	temp = (*pile);
	while (temp != NULL)
	{
		temp->target = 0;
		temp->cost = 0;
		temp->mouv = 0;
		temp->closet = 0;
		temp->sens = 0;
		temp = temp->next;
	}
}

int	min_max(t_push **pile, int value)
{
	t_push	*temp;
	int		i;

	temp = (*pile);
	i = temp->content;
	if (value == 0)
	{
		while (temp != NULL)
		{
			if (i < temp->content)
				i = temp->content;
			temp = temp->next;
		}
	}
	else
	{
		while (temp != NULL)
		{
			if (i > temp->content)
				i = temp->content;
			temp = temp->next;
		}
	}
	return (i);
}

void	mouv_zero(t_push *tempA, t_push *tempB, t_push **pileA, t_push **pileB)
{
	if (tempA->mouv >= tempB->mouv)
	{
		tempA->mouv -= tempB->mouv;
		while (tempB->mouv-- > 0)
			rr(pileA, pileB);
		while (tempA->mouv-- > 0)
			ra(pileA);
	}
	else if (tempA->mouv <= tempB->mouv)
	{
		tempB->mouv -= tempA->mouv;
		while (tempA->mouv-- > 0)
			rr(pileA, pileB);
		while (tempB->mouv-- > 0)
			rb(pileB);
	}
}

void	mouv_un(t_push *tempA, t_push *tempB, t_push **pileA, t_push **pileB)
{
	if (tempA->mouv >= tempB->mouv)
	{
		tempA->mouv -= tempB->mouv;
		while (tempB->mouv-- > 0)
			rrr(pileA, pileB);
		while (tempA->mouv-- > 0)
			rra(pileA);
	}
	else if (tempA->mouv <= tempB->mouv)
	{
		tempB->mouv -= tempA->mouv;
		while (tempA->mouv-- > 0)
			rrr(pileA, pileB);
		while (tempB->mouv-- > 0)
			rrb(pileB);
	}	
}

void	mouv_opp(t_push *tempA, t_push *tempB, t_push **pileA, t_push **pileB)
{
	if (tempA->sens == 0)
		while (tempA->mouv-- > 0)
			ra(pileA);
	else
		while (tempA->mouv-- > 0)
			rra(pileA);
	if (tempB->sens == 0)
		while (tempB->mouv-- > 0)
			rb(pileB);
	else
		while (tempB->mouv-- > 0)
			rrb(pileB);
}
