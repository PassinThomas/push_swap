/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:07:05 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/28 05:14:01 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	int nbr;
	int nbr2;
	t_stack *tmp;

	if (!stack || !stack->nbr || !stack->next->nbr)
		return ;
	tmp = stack;
	nbr = tmp->nbr;
	nbr2 = tmp->next->nbr;
	tmp->nbr = nbr2;
	tmp->next->nbr = nbr;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putstr_fd("ss\n", 1);
}
