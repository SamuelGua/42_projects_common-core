/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:06 by scely             #+#    #+#             */
/*   Updated: 2024/01/24 18:09:24 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_p(t_push *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_push	*ft_lstlast_p(t_push *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_push	*ft_lstnew_p(int content)
{
	t_push	*new;

	new = ft_calloc(sizeof(t_push), 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_p(t_push **lst, t_push *new)
{
	t_push	*liste;

	if (*lst != NULL)
	{
		liste = ft_lstlast_p(*lst);
		liste->next = new;
	}
	else if (*lst == NULL)
		*lst = new;
}

void	ft_lstadd_front_p(t_push **lst, t_push *new)
{
	new->next = *lst;
	*lst = new;
}
