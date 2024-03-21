/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:16:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/21 05:37:04 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	mouv(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		return (pa(a, b), 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (pb(a, b), 1);
	else if (ft_strcmp(line, "sa\n") == 0)
		return (sa(a), 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (sb(b), 1);
    else if (ft_strcmp(line, "sb\n") == 0)
        return ()
}

int	main(void)
{
	return (0);
}