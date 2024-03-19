/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:27:31 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/19 06:21:25 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mouv_top(t_stack *target, t_stack **stack_a, t_stack **stack_b)
{
	while (target->daron->index != 0 && target->index != 0)
	{
		rr(stack_a, stack_b);
		update_index(*stack_a);
		update_index(*stack_b);
	}
	if (target->daron->index != 0)
	{
		while (target->daron->index != 0)
		{
			ra(stack_a);
			update_index(*stack_a);
		}
	}
	else
	{
		while (target->index != 0)
		{
			rb(stack_b);
			update_index(*stack_b);
		}
	}
}

void	mouv_bottom(t_stack *target, t_stack **stack_a, t_stack **stack_b)
{
	while (target->daron->index != 0 && target->index != 0)
	{
		rrr(stack_a, stack_b);
		update_index(*stack_a);
		update_index(*stack_b);
	}
	if (target->daron->index != 0)
	{
		while (target->daron->index != 0)
		{
			rra(stack_a);
			update_index(*stack_a);
		}
	}
	else
	{
		while (target->index != 0)
		{
			rrb(stack_b);
			update_index(*stack_b);
		}
	}
}

void	mouv_top_bot(t_stack *target, t_stack **stack_a, t_stack **stack_b)
{
	while (target->index != 0)
	{
		rrb(stack_b);
		update_index(*stack_b);
	}
	while (target->daron->index != 0)
	{
		ra(stack_a);
		update_index(*stack_a);
	}
}

void	mouv_bot_top(t_stack *target, t_stack **stack_a, t_stack **stack_b)
{
	while (target->index != 0)
	{
		rb(stack_b);
		update_index(*stack_b);
	}
	while (target->daron->index != 0)
	{
		rra(stack_a);
		update_index(*stack_a);
	}		
}
