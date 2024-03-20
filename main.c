/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/16 00:09:01 by tpassin          ###   ########.fr       */
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
			return (ft_clean(&headA), 1);
		if (nb == 2)
			sort_2(&headA);
		else if (nb == 3)
			sort_3(&headA);
		else
			sort_all(&headA, &headB);
		ft_clean(&headA);
	}
	return (0);
}
