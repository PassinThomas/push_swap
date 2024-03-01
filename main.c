/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/01 04:38:32 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int val_max(int *tab, int size)
{
    int max;
    int i;
    
	max = tab[0];
	i = 1;
    while (i < size)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

int val_min(int *tab, int size)
{
    int min;
    int i;
    
	min = tab[0];
	i = 1;
    while (i < size)
    {
        if (tab[i] < min)
            min = tab[i];
        i++;
    }
    return (min);
}

void	insert_list(char **av, t_stack **headA, int *nb)
{
	int	i;
	int j;
	int	*tab;

	i = 0;
	j = 0;
	*nb = 0;
	tab = ft_parse(av, &i);
	if (tab)
	{
		while (j < i)
		{
			add_back(headA, new_stack(tab[j++]));
			(*nb)++;
		}
		(*headA)->max = val_max(tab, i);
		(*headA)->min = val_min(tab, i);
	}
	free(tab);
	return ;
}

int main(int ac, char **av)
{
	t_stack	*headA;
	t_stack	*headB;
	t_stack *tmp;
	int	nb;

	nb = 0;
	headA = NULL;
	headB = NULL;
	if (ac > 1)
	{
		insert_list(av, &headA, &nb);
		// printf("%d\n", headA->max);
		// printf("%d\n", headA->min);
		if (nb == 2)
			sort_2(&headA);
		else if (nb == 3)
			sort_3(&headA);
		else if (nb == 5)
			sort_5(&headA, &headB);
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
