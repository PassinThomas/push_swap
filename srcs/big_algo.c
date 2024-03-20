/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:15:07 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/20 05:40:21 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	median;

	median = ((find_min(*stack_a)->nbr + find_max(*stack_a)->nbr) / 2);
	while (sizelist(*stack_a) != 3 && !stack_sort(*stack_a))
	{
		if ((!*stack_b))
			pb(stack_a, stack_b);
		else if ((*stack_a)->nbr > median)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			pb(stack_a, stack_b);
	}
	sort_3(stack_a);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (max->nbr < tmp->nbr)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = stack;
	min = stack;
	while (tmp)
	{
		if (min->nbr > tmp->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
