/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:23:14 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/29 02:46:29 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		last = lstlast(tmp);
		last->next = tmp;
		last->next->next = NULL;
	}
}

void	rb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		last = lstlast(tmp);
		last->next = tmp;
		last->next->next = NULL;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
