/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:49:03 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/19 06:39:17 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	to_the_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	while (min->index != 0)
	{
		if (min->status == 0)
		{
			ra(a);
			update_index(*a);
		}
		else
		{
			rra(a);
			update_index(*a);
		}
	}
}

void	sort_2(t_stack **stack)
{
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
	else
		return ;
}

void	sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	thrd;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	thrd = (*stack)->next->next->nbr;
	if (first > second && first < thrd && second < thrd)
		sa(stack);
	else if (first < second && first > thrd && second > thrd)
		rra(stack);
	else if (first > second && first > thrd && second < thrd)
		ra(stack);
	else if (first > second && first > thrd && second > thrd)
	{
		ra(stack);
		sa(stack);
	}
	else if (first < second && first < thrd && second > thrd)
	{
		sa(stack);
		ra(stack);
	}
}

int	stack_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_all(t_stack **stack_a, t_stack	**stack_b)
{
	t_stack	*target;
	if (stack_sort(*stack_a))
		return (ft_clean(stack_a));
	push_a_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		update_index(*stack_a);
		update_index(*stack_b);
		find_daron(*stack_a, *stack_b);
		target = calcul_price(*stack_b);
		while(target->index != 0 || target->daron->index != 0)
		{
			if (target->daron->status == target->status && target->status == 0)
				mouv_top(target, stack_a, stack_b);
			else if (target->daron->status == target->status && target->status == 1)
				mouv_bottom(target, stack_a, stack_b);
			else if (target->daron->status == 0 && target->status == 1)
				mouv_top_bot(target, stack_a, stack_b);
			else
				mouv_bot_top(target, stack_a, stack_b);
		}
		pa(stack_a, stack_b);
	}
	update_index(*stack_a);
	to_the_top(stack_a);
}
