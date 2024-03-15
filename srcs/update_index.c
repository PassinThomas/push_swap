/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:10:26 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/15 04:54:48 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = stack->next;
	min = stack;
	while (tmp->next)
	{
		if (min->nbr > tmp->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

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
		// if (i > median)
		// 	stack->status = 1;
		// else
		// 	stack->status = 0;
		i++;
		stack = stack->next;
	}
}

int price(t_stack *node, t_stack *s)
{
	if (node->status == 0)
		return (node->index);
	int size = sizelist(s);
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

void	find_daron(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int			min_total;
	t_stack			*pere;
	int				total;

	// update_index(stack_b);
	// update_index(stack_a);
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
		// printf("VAL IS %i[%i]S{%i} daron %i[%i]S{%i}\n", tmp_b->nbr, price(tmp_b, stack_b), tmp_b->status, tmp_b->daron->nbr, price(tmp_b->daron, stack_a), tmp_b->daron->status);
		// printf("PRICE OF %i is %i\n", tmp_b->nbr, price(tmp_b, stack_b));
		// printf("PRIX DARON(%i) est %i\n", tmp_b->daron->nbr, price(tmp_b->daron, stack_a));
		total = get_total(tmp_b, stack_b, stack_a);
		// printf("total price: %d\tdaron index: %d\tstack_b index: %d\tnbr stack b[%d]\n", total, tmp_b->daron->index, tmp_b->index, tmp_b->nbr);
		tmp_b->prix = total;
		// printf("prix: %d\tnbr: %d\n", tmp_b->prix, tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
}
