/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:54:27 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/19 05:23:46 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	insert_list(char **av, t_stack **headA, int *nb)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	*nb = 0;
	tab = ft_parse(av, &i);
	if (tab)
	{
		while (j < i)
		{
			add_back(headA, new_stack(tab[j]));
			j++;
			(*nb)++;
		}
		free(tab);
	}
	else
		exit(1);
}
