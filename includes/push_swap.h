/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:05:02 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/19 05:23:02 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				status;
	int				prix;
	struct s_stack	*daron;
	struct s_stack	*next;
}					t_stack;

/*parsing*/
char				**join_arg(char **av);
int					check_sign(int c);
int					check_doublon(int *tab, int size);
void				insert_list(char **av, t_stack **headA, int *nb);
int					*ft_parse(char **av, int *i);
void				add_front(t_stack **stack, t_stack *new);
void				add_back(t_stack **stack, t_stack *new);
void				ft_clean(t_stack **stack);
int					sizelist(t_stack *stack);
t_stack				*new_stack(int nbr);
t_stack				*lstlast(t_stack *stack);
int					sizelist(t_stack *stack);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);


/*operation*/
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack_a, t_stack **stack_b);

/*algo*/
int					stack_sort(t_stack *stack);
void				sort_2(t_stack **stack);
void				sort_3(t_stack **stack);
void				sort_all(t_stack **stack_a, t_stack **stack_b);
void				push_a_to_b(t_stack **stack_a, t_stack **stack_b);

/* update index */
void	find_daron(t_stack *stack_a, t_stack *stack_b);
int		get_total(t_stack *stack_b, t_stack *b_daron, t_stack *stack_a);
void	update_index(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*calcul_price(t_stack *stack);

/*Mouv*/
void    mouv_top(t_stack *target, t_stack **stack_a, t_stack **stack_b);
void    mouv_bottom(t_stack *target, t_stack **stack_a, t_stack **stack_b);
void    mouv_top_bot(t_stack *target, t_stack **stack_a, t_stack **stack_b);
void	mouv_bot_top(t_stack *target, t_stack **stack_a, t_stack **stack_b);

#endif
