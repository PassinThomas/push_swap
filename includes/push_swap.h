/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:05:02 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/27 05:12:34 by tpassin          ###   ########.fr       */
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
    int             nbr;
    int             pos;
    struct t_stack  *next;
}               t_stack;

char	**join_arg(char **av);
int     check_sign(int c);
int     check_doublon(int *tab, int size);
t_stack *new_stack(int nbr);
void    stack_add_back(t_stack **stack, t_list *new);
void    stack_add_front(t_stack **stack, t_list *new);



# endif
