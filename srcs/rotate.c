/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:23:14 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/28 05:46:17 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ra(t_stack **stack)
{
    if (!stack || !*stack)
        return ; 
    if ((*stack)->next)
    {
        t_stack *tmp;
        
        tmp = *stack;
        *stack = (*stack)->next;
        ft_lstadd_back(stack, tmp);
    }
}