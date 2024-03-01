/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:05:02 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/01 03:25:20 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
    int			nbr;
    int			pos;
    int         max;
    int         min;
    struct s_stack	*next;
}		t_stack;

/*parsing*/
char	**join_arg(char **av);
int     check_sign(int c);
int     check_doublon(int *tab, int size);
int     *ft_parse(char **av, int *i);
t_stack *new_stack(int nbr);
t_stack	*lstlast(t_stack *stack);
void	add_front(t_stack **stack, t_stack *new);
void	add_back(t_stack **stack, t_stack *new);
void    ft_clean(t_stack **stack);

/*operation*/
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    swap_a_b(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/*algo*/
void    sort_2(t_stack **stack);
void    sort_3(t_stack **stack);
void    sort_5(t_stack **stack_a, t_stack **stack_b);

# endif
