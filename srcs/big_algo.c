/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:15:07 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/17 09:09:43 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (sizelist(*stack_a) > 3)
        pb(stack_a, stack_b);
}
