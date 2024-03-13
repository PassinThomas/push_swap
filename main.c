/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/12 15:38:44 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack	*headA;
	t_stack	*headB;
	// t_stack *tmp;
	int	nb;

	nb = 0;
	headA = NULL;
	headB = NULL;
	if (ac > 1)
	{
		insert_list(av, &headA, &nb);
		if (nb == 1)
			return (1);
		if (nb == 2)
			sort_2(&headA);
		else if (nb == 3)
			sort_3(&headA);
		// else
		// 	sort_all(&headA, &headB);
		if (headA)
		{
		// 	// tmp = headA;
		// 	// while(tmp)
		// 	// {
		// 	// 	printf("%d\n", tmp->nbr);
		// 	// 	tmp = tmp->next;
		//  	// }
			ft_clean(&headA);
			if (headB)
				ft_clean(&headB);
		}
	}
	return (0);
}
