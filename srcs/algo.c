/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:49:03 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/12 14:52:11 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	visual_stack(t_stack *a, t_stack *b)
{
	printf("[a]	[b]\n");
	while (a || b)
	{
		if (a == NULL)
			printf("-\t");
		else
			printf("{%d}\t", a->nbr);
		if (b == NULL)
			printf("-\n");
		else
			printf("{%d}\n", b->nbr);
		if (a)
			a = a->next;
		if (b)
		b = b->next;
	}
	printf("\n");
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
	t_stack *tmp;

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
	push_a_to_b(stack_a, stack_b);
}