/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:23:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/01 05:42:10 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_sign(int c)
{
	return (c == '+' || c == '-');
}

void	swap_max(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->nbr == (*stack)->max);
		{
			tmp->nbr = (*stack)->max;
			break ;
		}
		tmp = tmp->next;	
	}
	
	
}
