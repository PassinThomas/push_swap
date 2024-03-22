/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:23:14 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/22 02:58:14 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **stack)
{
	rotate(stack);
}

void	rb(t_stack **stack)
{
	rotate(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
