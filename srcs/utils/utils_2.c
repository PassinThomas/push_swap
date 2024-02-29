/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:51:21 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/29 04:04:31 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*lstlast(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (stack)
	{
		if (*stack == NULL)
			*stack = new;
		else
		{
			tmp = lstlast(*(stack));
			tmp->next = new;
		}
	}
}

t_stack	*new_stack(int nbr)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->nbr = nbr;
	stack->next = NULL;
	return (stack);
}

void ft_clean(t_stack **stack)
{
	t_stack *current;
	t_stack *next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
