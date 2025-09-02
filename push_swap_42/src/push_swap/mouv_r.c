/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:46:26 by scely             #+#    #+#             */
/*   Updated: 2024/01/22 18:21:36 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push **pile_A)
{
	t_push	*temp;
	t_push	*last;

	if ((*pile_A)->next == NULL)
		return ;
	last = ft_lstlast_p(*pile_A);
	temp = (*pile_A)->next;
	(*pile_A)->next = NULL;
	last->next = (*pile_A);
	(*pile_A) = temp;
	write(1, "ra\n", 3);
}

void	rb(t_push **pile_B)
{
	t_push	*temp;
	t_push	*last;

	if ((*pile_B)->next == NULL)
		return ;
	last = ft_lstlast_p(*pile_B);
	temp = (*pile_B)->next;
	(*pile_B)->next = NULL;
	last->next = (*pile_B);
	(*pile_B) = temp;
	write(1, "rb\n", 3);
}

void	rr(t_push **pile_A, t_push **pile_B)
{
	t_push	*temp;
	t_push	*last;

	if ((*pile_A)->next == NULL)
		return ;
	last = ft_lstlast_p(*pile_A);
	temp = (*pile_A)->next;
	(*pile_A)->next = NULL;
	last->next = (*pile_A);
	(*pile_A) = temp;
	if ((*pile_B)->next == NULL)
		return ;
	last = ft_lstlast_p(*pile_B);
	temp = (*pile_B)->next;
	(*pile_B)->next = NULL;
	last->next = (*pile_B);
	(*pile_B) = temp;
	write(1, "rr\n", 3);
}
