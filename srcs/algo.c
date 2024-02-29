/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:49:03 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/29 05:42:18 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_2(t_stack **stack)
{
    int first;
    int second;

    first = (*stack)->nbr;
    second = (*stack)->next->nbr;
    
    if (first > second)
	    sa(stack);
}

void    sort_3(t_stack **stack)
{
    int first;
    int second;
    int thrd;
    
    first = (*stack)->nbr;
    second = (*stack)->next->nbr;
    thrd = (*stack)->next->next->nbr;
    if (first > second && first > thrd && second > thrd)
    {
        ra(stack);
        sa(stack);
    }
    else if (first > second && first < thrd && second < first)
        sa(stack);
    else if (first < second && first > thrd && second > thrd)
        rra(stack);
    else if (first > second && first > thrd && second < thrd)
        ra(stack);
    else if (first < second && first < thrd && second > thrd)
    {
        sa(stack);
        ra(stack);
    }
}
