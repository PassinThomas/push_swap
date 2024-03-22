/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:16:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/22 05:48:12 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <string.h>

int	mouv(t_stack **a, t_stack **b, char *line)
{
	if (strcmp(line, "pa\n") == 0)
		return (pa(a, b), 1);
	else if (strcmp(line, "pb\n") == 0)
		return (pb(a, b), 1);
	else if (strcmp(line, "sa\n") == 0)
		return (sa(a), 1);
	else if (strcmp(line, "sb\n") == 0)
		return (sb(b), 1);
	else if (strcmp(line, "ss\n") == 0)
		return (ss(a, b), 1);
	else if (strcmp(line, "ra\n") == 0)
		return (ra(a), 1);
	else if (strcmp(line, "rb\n") == 0)
		return (rb(b), 1);
	else if (strcmp(line, "rr\n") == 0)
		return (rr(a, b), 1);
	else if (strcmp(line, "rra\n") == 0)
		return (rra(a), 1);
	else if (strcmp(line, "rrb\n") == 0)
		return (rrb(b), 1);
	else if (strcmp(line, "rrr\n") == 0)
		return (rrr(a, b), 1);
	return (0);
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

int	valid(t_stack *a, t_stack *b)
{
	if (stack_sort(a) && sizelist(b) == 0)
		return (ft_clean(&a), ft_putstr_fd("OK\n", 1), 1);
	else
		return (ft_putstr_fd("KO\n", 1), ft_clean(&a), ft_clean(&b), 0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		nb;

	stack_a = NULL;
	stack_b = NULL;
	nb = 0;
	if (ac > 1)
	{
		insert_list(av, &stack_a, &nb);
		while (1)
		{
			line = get_next_line(0);
			if (!line)
				break ;
			if (mouv(&stack_a, &stack_b, line))
				free(line);
			else
				return (ft_putstr_fd("Error\n", 2), ft_clean(&stack_a),
					ft_clean(&stack_a), 0);
		}
		return (valid(stack_a, stack_b));
	}
	return (0);
}
