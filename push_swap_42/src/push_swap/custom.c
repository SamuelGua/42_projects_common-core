/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:11:00 by meca_971          #+#    #+#             */
/*   Updated: 2024/01/25 15:31:15 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_push **pile, t_push **pile_b, int i, char **av)
{
	t_push	*temp_a;

	while ((*pile) != NULL)
	{
		temp_a = (*pile)->next;
		free((*pile));
		(*pile) = temp_a;
	}
	if (i == 0)
		ft_free(av);
	free(pile_b);
	free(pile);
}

void	custom(t_push **pile)
{
	int		j;
	t_push	*temp;

	j = 0;
	temp = (*pile);
	while (j < (ft_lstsize_p(*pile) / 2))
	{
		temp->mouv = j;
		temp->sens = 0;
		temp = temp->next;
		j++;
	}
	if (ft_lstsize_p(*pile) % 2 != 0)
	{
		temp->mouv = j;
		temp->sens = 0;
		temp = temp->next;
	}
	while (temp != NULL)
	{
		temp->mouv = j;
		temp->sens = 1;
		temp = temp->next;
		j--;
	}	
}

void	custom_a_bis_zero(t_push *tempA, t_push *tempB, int max)
{
	while (tempB->content != max)
		tempB = tempB->next;
	if (tempA->sens == tempB->sens)
	{
		if (tempA->mouv > tempB->mouv)
			tempA->cost = tempA->mouv + 1;
		else
			tempA->cost = tempB->mouv + 1;
	}
	else
		tempA->cost = tempA->mouv + tempB->mouv + 1;
	tempA->target = max;
}

void	custom_a_bis_un(t_push *tempA, t_push	*tempB)
{
	int	i;

	while (tempB != NULL)
	{
		i = tempA->content - tempB->content;
		if (i < 0)
			i *= -1;
		if (tempA->closet > i || tempA->closet == 0)
		{
			tempA->closet = i;
			tempA->target = tempB->content;
			if (tempA->sens == tempB->sens)
			{
				if (tempA->mouv >= tempB->mouv)
					tempA->cost = tempA->mouv +1;
				else
					tempA->cost = tempB->mouv +1;
			}
			else
				tempA->cost = tempA->mouv + tempB->mouv +1;
		}
		tempB = tempB->next;
	}	
}

void	custom_a(t_push **pile_a, t_push **pile_b)
{
	t_push	*tempa;
	t_push	*tempb;
	int		max;
	int		min;

	tempa = (*pile_a);
	custom(pile_a);
	custom(pile_b);
	while (tempa != NULL)
	{
		max = min_max(pile_b, 0);
		min = min_max(pile_b, 1);
		tempb = (*pile_b);
		if (tempa->content > max || tempa->content < min)
			custom_a_bis_zero(tempa, tempb, max);
		else
			custom_a_bis_un(tempa, tempb);
		tempa = tempa->next;
	}	
}
