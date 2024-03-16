/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:49:03 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/16 09:44:25 by tpassin          ###   ########.fr       */
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

void printstacks(t_stack *a, t_stack *b)
{
	t_stack *tmp = a;

	int i = 0;
	while (tmp)
	{
		printf("[%i]\t%i\n", i++, tmp->nbr);
		tmp = tmp->next;
	}
	printf("STACK A\n");
	tmp = b;
	i = 0;
	while (tmp)
	{
		printf("[%i]\t%i\n", i++, tmp->nbr);
		tmp = tmp->next;
	}
	printf("STACK B\n");
}

void	mouv_top(t_stack *a, t_stack *b)
{
	if (a->status == 0 && b->status == 0)
	{
		while (a->index != 0 && b->index != 0)
		{
			rr(&a, &b);
			update_index(a);
			update_index(b);
		}
		if (a->index != 0)
		{
			while (a->index != 0)
			{
				ra(&a);
				update_index(a);
			}
		}
		else if (b->index != 0)
		{
			while (b->index != 0)
			{
				rb(&b);
				update_index(b);
			}
		}
	}
}

void	mouv_bottom(t_stack *a, t_stack *b)
{
	if (a->status == 1 && b->status == 1)
	{
		while (a->index != 0 && b->index != 0)
		{
			rrr(&a, &b);
			update_index(a);
			update_index(b);
		}
		if (a->index != 0)
		{
			while (a->index != 0)
			{
				rra(&a);
				update_index(a);
			}
		}
		else if (b->index != 0)
		{
			while (b->index != 0)
			{
				rrb(&b);
				update_index(b);
			}
		}
	}
}

void mouv_bottom_top(t_stack *a, t_stack *b)
{
	if ((a)->status == 1 && b->status == 0)
	{
		while(a->index != 0)
		{
			rra(&a);
			update_index(a);
		}
		while (b->index != 0)
		{
			rb(&b);
			update_index(b);
		}
	}
}

void mouv_top_bottom(t_stack *a, t_stack *b)
{
	if (a->status == 0 && b->status == 1)
	{
		while(a->index != 0)
		{
			ra(&a);
			update_index(a);
		}
		while (b->index != 0)
		{
			rrb(&b);
			update_index(b);
		}
	}
}

void	sort_all(t_stack **stack_a, t_stack	**stack_b)
{
	if (stack_sort(*stack_a))
		return (ft_clean(stack_a));
	// tout push dans b sauf 3
	// algo de 3
	push_a_to_b(stack_a, stack_b);
	// printstacks(*stack_a, *stack_b);
	// t_stack *tmp = *stack_b;
	while (*stack_b)
	{
		find_daron(*stack_a, *stack_b);
		mouv_top(*stack_a, *stack_b);
		mouv_bottom(*stack_a, *stack_b);
		mouv_bottom_top(*stack_a, *stack_b);
		mouv_top_bottom(*stack_a, *stack_b);
		pa(stack_a, stack_b);
	}
	// printstacks(*stack_a, *stack_b);
	update_index(*stack_a);
	/*
	while (b) ok
	{
		int min_total = INT_MAX;
		while (b)
		{
			trouver daron de chaque element selon a
			int pere = daron(b->value, a); ok
			int prix_a = price(daron);
			int prix_b = price(b->value);
			int total = calctotal(prix_a, prix_b);
			if (total < min_total)
			{
				int price_to_exec_a = prix_a
				int price_to_exec_b = prix_b
				total = min_total
			}
		}
		exec(price_to_exec_a,price_to_exec_b);
	}
	// algo fini
	*/
}
