/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:49:03 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/18 17:20:56 by tpassin          ###   ########.fr       */
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

// void sort_3(t_stack **stack)
// {
//     int first = (*stack)->nbr;
//     int second = (*stack)->next->nbr;
//     int third = (*stack)->next->next->nbr;

//     // Si les trois éléments sont déjà triés, aucune action n'est nécessaire
//     if (first <= second && second <= third) return;

//     // Si le premier élément est le plus grand, il doit être déplacé à la fin
//     if (first > second && first > third) {
//         ra(stack);
//         sa(stack);
//     }
//     // Si le deuxième élément est le plus grand, il doit être déplacé à la fin
//     else if (second > first && second > third) {
//         rra(stack);
//     }
//     // Si le troisième élément est le plus grand, il doit être déplacé à la fin
//     else if (third > first && third > second) {
//         ra(stack);
//         sa(stack);
//     }
// }

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
	printf("STACK A\n");
	while (tmp)
	{
		printf("index:[%i]\tnbr: %i\n", tmp->index, tmp->nbr);
		tmp = tmp->next;
	}
	tmp = b;
	i = 0;
	printf("STACK B\n");
	while (tmp)
	{
		printf("[%i]\t%i\n", i++, tmp->nbr);
		tmp = tmp->next;
	}
}

// int	mouv_top(t_stack **a, t_stack **b, t_stack *target)
// {
// 	if (target->daron->status == 0 && target->status == 0)
// 	{
// 		while (target->daron->index != 0 && target->index != 0)
// 		{
// 			rr(a, b);
// 			update_index(*a);
// 			update_index(*b);
// 		}
// 		if (target->daron->index != 0)
// 		{
// 			while (target->daron->index != 0)
// 			{
// 				ra(a);
// 				update_index(*a);
// 			}
// 		}
// 		else
// 		{
// 			while (target->index != 0)
// 			{
// 				rb(b);
// 				update_index(*b);
// 			}
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

// int	mouv_bottom(t_stack **a, t_stack **b, t_stack *target)
// {
// 	if (target->daron->status == target->status)
// 	{
// 		while (target->daron->index != 0 && target->index != 0)
// 		{
// 			rrr(a, b);
// 			update_index(*a);
// 			update_index(*b);
// 		}
// 		if (target->daron->index != 0)
// 		{
// 			while (target->daron->index != 0)
// 			{
// 				rra(a);
// 				update_index(*a);
// 			}
// 		}
// 		else
// 		{
// 			while (target->index != 0)
// 			{
// 				rrb(b);
// 				update_index(*b);
// 			}
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

// int mouv_bottom_top(t_stack **a, t_stack **b, t_stack *target)
// {
// 	if (target->daron->status == 1 && target->status == 0)
// 	{
// 		while(target->daron->index != 0)
// 		{
// 			rra(a);
// 			update_index(*a);
// 		}
// 		while (target->index != 0)
// 		{
// 			rb(b);
// 			update_index(*b);
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

// int mouv_top_bottom(t_stack **a, t_stack **b, t_stack *target)
// {
// 	if (target->daron->status == 0 && target->status == 1)
// 	{
// 		while(target->daron->index != 0)
// 		{
// 			ra(a);
// 			update_index(*a);
// 		}
// 		while (target->index != 0)
// 		{
// 			rrb(b);
// 			update_index(*b);
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

void	sort_all(t_stack **stack_a, t_stack	**stack_b)
{
	if (stack_sort(*stack_a))
		return (ft_clean(stack_a));
	push_a_to_b(stack_a, stack_b);
	sort_3(stack_a);
	// printstacks(*stack_a, *stack_a);
	t_stack *target;
	while (*stack_b)
	{
		update_index(*stack_a);
		update_index(*stack_b);
		find_daron(*stack_a, *stack_b);
		target = calcul_price(*stack_b);
		while(target->index != 0 || target->daron->index != 0)
		{
			if (target->daron->status == target->status && target->status == 0)
			{
				while(target->daron->index != 0 && target->index != 0)
				{
					rr(stack_a, stack_b);
					update_index(*stack_a);
					update_index(*stack_b);
				}
				if (target->daron->index != 0)
				{
					while(target->daron->index != 0)
					{
						// printstacks(*stack_a, *stack_b);
						ra(stack_a);
						update_index(*stack_a);
						// printstacks(*stack_a, *stack_b);
					}
				}
				else
				{
					while(target->index != 0)
					{
						rb(stack_b);
						update_index(*stack_b);
					}
				}
			}
			else if (target->daron->status == target->status && target->status == 1)
			{
				while(target->daron->index != 0 && target->index != 0)
				{
					// printf("target index: %d\ttarget daron index: %d\n", target->index, target->daron->index);
					rrr(stack_a, stack_b);
					update_index(*stack_a);
					update_index(*stack_b);
				}
				if (target->daron->index != 0)
				{
					while(target->daron->index != 0)
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
			else if (target->daron->status == 0 && target->status == 1)
			{
				while(target->index != 0)
				{
					// printf("target index rrb: %d\n", target->index);
					rrb(stack_b);
					update_index(*stack_b);
					// printf("target index rrb: %d\n", target->index);
				}
				while(target->daron->index != 0)
				{
					// printstacks(*stack_a, *stack_b);
					ra(stack_a);
					update_index(*stack_a);
					// printstacks(*stack_a, *stack_b);
				}
			}
			else
			{	
				while(target->index != 0)
				{
					rb(stack_b);
					update_index(*stack_b);
				}
				while(target->daron->index != 0)
				{
					rra(stack_a);
					update_index(*stack_a);
				}		
			}
		}
		pa(stack_a, stack_b);
			// printf("cible: %d\tcible index: [%d]\n", target->daron->nbr, target->daron->index);
			// printstacks(*stack_a, *stack_b);
	}
	update_index(*stack_a);
	to_the_top(stack_a);
	// printstacks(*stack_a, *stack_a);
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
