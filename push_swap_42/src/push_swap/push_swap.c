/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:11 by scely             #+#    #+#             */
/*   Updated: 2024/01/26 16:28:31 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_pile(t_push **pile_A, char **av, int i)
{
	t_push	*list;

	while (av[i])
	{
		if (check_numbers(av[i]) != 0 || len_nbrs(av[i]) != 0)
			return (-1);
		list = ft_lstnew_p(ft_atoi(av[i]));
		if (!list)
			return (-1);
		list->next = NULL;
		ft_lstadd_back_p(pile_A, list);
		i++;
	}
	return (0);
}

void	push_swap(t_push **pile_a, t_push **pile_b)
{
	if (ft_lstsize_p(*pile_a) <= 5)
		sort_nbrs_small_2(pile_a, pile_b);
	else if (ft_lstsize_p(*pile_a) > 5)
		all_insruction(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_push	**pile_a;
	t_push	**pile_b;
	int		i;

	i = 1;
	if (ac == 1)
		return (0);
	if ((ft_strchr(av[1], 32) != 0 && av[2] != NULL))
		return (ft_putstr_fd("Error\n", 2), 1);
	pile_a = ft_calloc(sizeof(t_push), 1);
	pile_b = ft_calloc(sizeof(t_push), 1);
	if (!pile_a || !pile_b)
		return (1);
	if (ac == 2 && ft_strchr(av[1], 32) != 0)
	{
		av = ft_split(av[1], 32);
		if (!av)
			return (1);
		i = 0;
	}
	if (set_pile(pile_a, av, i) != 0 || doublons(pile_a) != 0)
		return (ft_putstr_fd("Error\n", 2), free_lst(pile_a, pile_b, i, av), 1);
	if (list_sorted(pile_a) != 0)
		push_swap(pile_a, pile_b);
	return (free_lst(pile_a, pile_b, i, av), 0);
}
