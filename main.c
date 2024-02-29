/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/29 05:24:59 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	insert_list(char **av, t_stack **headA)
{
	int	i;
	int j;
	int	*tab;

	i = 0;
	j = 0;
	tab = ft_parse(av, &i);
	if (tab)
	{
		while (j < i)
		{
			add_back(headA, new_stack(tab[j++]));
		}
	}
	free(tab);
	return ;
}

int main(int ac, char **av)
{
	t_stack	*headA;
	t_stack	*headB;
	t_stack *tmp;

	headA = NULL;
	headB = NULL;
	if (ac > 1)
	{
		insert_list(av, &headA);
		if (ac == 3)
			sort_2(&headA);
		else if (ac == 4)
			sort_3(&headA);
		// else if (ac == 6)
		// 	sort_5(&headA);
		if (headA)
		{
			tmp = headA;
			while(tmp)
			{
				printf("%d\n", tmp->nbr);
				tmp = tmp->next;
			}
			ft_clean(&headA);
		}
	}
	return (0);
}
