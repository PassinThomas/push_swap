/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:10:26 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/19 05:31:03 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_index(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = sizelist(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->status = (i > median);
		i++;
		stack = stack->next;
	}
}

int	price(t_stack *node, t_stack *s)
{
	int	size;

	if (node->status == 0)
		return (node->index);
	size = sizelist(s);
	return (size - node->index);	
}

int	get_total(t_stack *stack_b, t_stack	*b_daron, t_stack *a)
{
	int		prix;

	if (stack_b->status == stack_b->daron->status)
	{
		if (price(stack_b, b_daron) > price(stack_b->daron, a))
			prix = price(stack_b, b_daron);
		else
			prix = price(stack_b->daron, a);
	}
	else
		prix = price(stack_b, b_daron) + price(stack_b->daron, a);
	return (prix);
}

t_stack	*calcul_price(t_stack *stack)
{
	t_stack	*best_price;
	t_stack	*tmp;

	best_price = stack;
	tmp = stack->next;
	while (tmp)
	{	
		if (best_price->prix > tmp->prix)
			best_price = tmp;
		tmp = tmp->next;
	}
	return (best_price);
}

void	find_daron(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*pere;
	int		min_total;
	int		total;

	tmp_b = stack_b;
	while (tmp_b)
	{
		tmp_a = stack_a;
		min_total = INT_MAX;
		while (tmp_a)
		{
			if (tmp_a->nbr > tmp_b->nbr && tmp_a->nbr < min_total)
			{
				min_total = tmp_a->nbr;
				pere = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (min_total == INT_MAX)
			tmp_b->daron = find_min(stack_a);
		else
			tmp_b->daron = pere;
		total = get_total(tmp_b, stack_b, stack_a);
		tmp_b->prix = total;
		tmp_b = tmp_b->next;
	}
}
