/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:22:40 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/20 22:30:22 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a && stack_b)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void	pa(t_stack **stack_A, t_stack **stack_B)
{
	push(stack_B, stack_A);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_A, t_stack **stack_B)
{
	push(stack_A, stack_B);
	ft_putstr_fd("pb\n", 1);
}
