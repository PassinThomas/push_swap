/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:10:26 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/12 16:27:33 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_min(t_stack *stack)
{
    t_stack *tmp;
    int     *min;

    tmp = stack->next;
    min = stack->nbr;
    while(tmp->next)
    {
        if (min > tmp->nbr)
            min = tmp->nbr;
        tmp = tmp->next;
    }
    return (min);
}

void    uptadte_index(t_stack *stack)
{
    int i;
    int median;
    
    if (!stack)
        return ;
    i = 0;
    median = sizelist(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->status = 0;
        else
            stack->status = 1;
        i++;
        stack = stack->next;
    }
}

void    update_target(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmpA;
    t_stack *target;
    int     *best_match;
    
    while (stack_b)
    {
        tmpA = stack_a;
        best_match = LONG_MAX;
        while (tmpA)
        {
               if (tmpA->nbr > stack_b->nbr && tmpA->nbr < best_match)
               {
                    best_match = tmpA->nbr;
                    target = tmpA;
               }
               tmpA = tmpA->next;
        }
        if (best_match == LONG_MAX)
            stack_b->target = find_min(stack_a);
        else
            stack_b->target = target;
        stack_b = stack_b->next;
    }    
}