/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:00:42 by scely             #+#    #+#             */
/*   Updated: 2024/01/25 10:37:05 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_less_cost(t_push **pileA)
{
	t_push	*temp_a;
	t_push	*temp_b;
	int		j;
	int		i;

	temp_a = (*pileA);
	i = temp_a->content;
	j = temp_a->cost;
	while (temp_a != NULL)
	{
		temp_b = temp_a->next;
		while (temp_b != NULL)
		{
			if (temp_a->cost < j)
			{
				i = temp_a->content;
				j = temp_a->cost;
			}
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	return (i);
}

void	turk_sorting(t_push **pileA, t_push **pileB)
{
	t_push	*temp_a;
	t_push	*temp_b;
	int		i;

	i = find_less_cost(pileA);
	temp_a = (*pileA);
	temp_b = (*pileB);
	while (temp_a->content != i)
		temp_a = temp_a->next;
	while (temp_a->target != temp_b->content && temp_b != NULL)
		temp_b = temp_b->next;
	if (temp_a->sens == temp_b->sens && temp_a->sens == 0)
		mouv_zero(temp_a, temp_b, pileA, pileB);
	else if (temp_a->sens == temp_b->sens && temp_a->sens == 1)
		mouv_un(temp_a, temp_b, pileA, pileB);
	else if (temp_a->sens != temp_b->sens)
		mouv_opp(temp_a, temp_b, pileA, pileB);
	if (temp_a->content < temp_b->content && temp_a->closet != 0)
		rb(pileB);
	pb(pileA, pileB);
}

void	target_sorting(t_push *temp_a, t_push *temp_b)
{
	int	i;

	while (temp_a != NULL)
	{
		i = temp_b->content - temp_a->content;
		if (i < 0)
			i *= -1;
		if (temp_b->closet > i || temp_b->closet == 0)
		{
			temp_b->closet = i;
			temp_b->target = temp_a->content;
		}
		temp_a = temp_a->next;
	}
}

void	final_sorting(t_push **pileA, t_push **pileB)
{
	t_push	*temp_a;
	t_push	*temp_b;

	temp_a = (*pileA);
	temp_b = (*pileB);
	(custom(pileA), custom(pileB));
	if (temp_b->content > min_max(pileA, 0))
		temp_b->target = min_max(pileA, 0);
	else if (temp_b->content < min_max(pileA, 1))
		temp_b->target = min_max(pileA, 1);
	else
		target_sorting(temp_a, temp_b);
	temp_a = (*pileA);
	while (temp_a->content != temp_b->target)
		temp_a = temp_a->next;
	if (temp_a->sens == temp_b->sens && temp_a->sens == 0)
		mouv_zero(temp_a, temp_b, pileA, pileB);
	else if (temp_a->sens == temp_b->sens && temp_a->sens == 1)
		mouv_un(temp_a, temp_b, pileA, pileB);
	else if (temp_a->sens != temp_b->sens)
		mouv_opp(temp_a, temp_b, pileA, pileB);
	if (temp_a->content < temp_b->content)
		ra(pileA);
	pa(pileA, pileB);
}

void	all_insruction(t_push **pile_a, t_push **pile_b)
{
	t_push	*temp_a;
	int		c;

	(pb(pile_a, pile_b), pb(pile_a, pile_b));
	while (ft_lstsize_p(*pile_a) > 3)
	{
		(custom_a(pile_a, pile_b), turk_sorting(pile_a, pile_b));
		(clear_param(pile_a), clear_param(pile_b));
	}
	sort_nbrs_small(pile_a);
	while (ft_lstsize_p((*pile_b)))
		final_sorting(pile_a, pile_b);
	temp_a = (*pile_a);
	if ((*pile_b) == NULL)
	{
		(custom(pile_a), c = min_max(pile_a, 1));
		while (temp_a->content != c)
			temp_a = temp_a->next;
		if (temp_a->sens == 0)
			while (temp_a->mouv--)
				ra(pile_a);
		else
			while (temp_a->mouv--)
				rra(pile_a);
	}
}
