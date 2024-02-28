/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:07:05 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/28 02:26:29 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
}

void	swap_a_b(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
