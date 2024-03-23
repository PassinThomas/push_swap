/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:16:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/23 07:59:08 by tpassin          ###   ########.fr       */
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

	if (!stack)
		return (0);
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
		return (ft_clean(&a), ft_putstr_fd("OK\n", 1), 0);
	else
		return (ft_putstr_fd("KO\n", 2), ft_clean(&a), ft_clean(&b), 1);
}

int	check_loop(t_stack *a, t_stack *b, char *line, int c)
{
	while (1)
	{
		line = get_next_line(0, &c);
		if (!line)
			break ;
		if (mouv(&a, &b, line))
			free(line);
		else
		{
			free(line);
			return (ft_putstr_fd("Error\n", 2), ft_clean(&a), ft_clean(&b), 1);
		}
		if (c == 0)
			break ;
	}
	if (!c)
		return (ft_clean(&a), ft_clean(&b), 1);
	return (valid(a, b));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		nb;
	int		b;

	line = NULL;
	stack_a = NULL;
	stack_b = NULL;
	nb = 0;
	b = 1;
	if (ac > 1)
	{
		insert_list(av, &stack_a, &nb);
		if (!check_loop(stack_a, stack_b, line, b))
			return (1);
	}
	return (0);
}
