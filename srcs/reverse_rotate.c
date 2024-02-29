/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 05:22:01 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/29 01:50:54 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*before_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	rra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*new_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	new_head = lstlast(*stack);
	tmp = before_last(*stack);
	add_front(stack, new_head);
	tmp->next = NULL;
}

void	rrb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*new_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	new_head = lstlast(*stack);
	tmp = before_last(*stack);
	add_front(stack, new_head);
	tmp->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
