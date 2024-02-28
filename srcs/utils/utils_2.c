/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:59:54 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/27 22:15:42 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *new_stack(int nbr)
{
    t_stack *stack;
    
    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->nbr = nbr;
    stack->next = NULL;
    return (stack);
}

void    stack_add_back(t_stack **stack, t_list *new)
{
    t_stack *tmp;

    if (stack)
    {
        if (!*stack)
            *stack = new;
        else
        {
            tmp = ft_lstlast(*stack);
            tmp->next = new;
        }
    }
}

void    stack_add_front(t_stack **stack, t_list *new)
{
    new->next = *stack;
    *stack = new;
}