/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:49:03 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/01 05:19:50 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_stack **stack)
{
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}

void	sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	thrd;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	thrd = (*stack)->next->next->nbr;
	if (first > second && first > thrd && second > thrd)
	{
		ra(stack);
		sa(stack);
	}
	else if (first > second && first < thrd && second < first)
		sa(stack);
	else if (first < second && first > thrd && second > thrd)
		rra(stack);
	else if (first > second && first > thrd && second < thrd)
		ra(stack);
	else if (first < second && first < thrd && second > thrd)
	{
		sa(stack);
		ra(stack);
	}
}

void    sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	thrd;
	int	fourth;
	int	fifth;

	first = (*stack_a)->nbr;
	second = (*stack_a)->next->nbr;
	thrd = (*stack_a)->next->next->nbr;
	fourth = (*stack_a)->next->next->next->nbr;
	fifth = (*stack_a)->next->next->next->next->nbr;
	if (first > second)
		sa(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

