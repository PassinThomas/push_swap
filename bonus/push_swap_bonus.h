/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:15:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/20 22:42:42 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
void				insert_list(char **av, t_stack **head_a, int *nb);
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

#endif