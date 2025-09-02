/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:35 by scely             #+#    #+#             */
/*   Updated: 2024/01/25 14:02:22 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_push **pile)
{
	t_push	*temp;

	temp = *pile;
	if (temp->next == NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sort_nbrs_small(t_push **pile)
{
	if (min_max(pile, 0) == (*pile)->content)
		ra(pile);
	else if (min_max(pile, 0) == (*pile)->next->content)
		rra(pile);
	if (list_sorted(pile) != 0)
		sa(pile);
}

void	sort_nbrs_small_2(t_push **pilea, t_push **pileb)
{
	t_push	*temp;
	int		i;

	i = 0;
	temp = *pilea;
	while (ft_lstsize_p(*pilea) > 3)
	{
		custom(pilea);
		i = min_max(pilea, 1);
		while (temp->content != i)
			temp = temp->next;
		if (temp->sens == 0)
			while (temp->mouv--)
				ra(pilea);
		else
			while (temp->mouv--)
				rra(pilea);
		clear_param(pilea);
		pb(pilea, pileb);
		temp = (*pilea);
	}
	sort_nbrs_small(pilea);
	while (ft_lstsize_p(*pileb) > 0)
		pa(pilea, pileb);
}
