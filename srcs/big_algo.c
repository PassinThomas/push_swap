/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:15:07 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/12 13:09:13 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    if (!*stack_a || !stack_a)
        return ;

    tmp = *stack_a;
    while (*stack_a && sizelist(*stack_a) > 3)
    {
        if((*stack_a)->nbr && (!*stack_b))
        {
            pb(stack_a, stack_b);
        }
        else if ((*stack_a)->nbr <= tmp->median)
            pb(stack_a, stack_b);
        else
        {
            pb(stack_a, stack_b);
            rb(stack_b);
        }
    }
    sort_3(stack_a);
}

