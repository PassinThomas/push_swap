/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/27 23:04:06 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// void	insert_list(int *tab, t_list **headA)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		ft_lstadd_back(headA, ft_lstnew(tab[i++]));
// 	}
// 	return ;
// }

int main(int ac, char **av)
{
	// t_list	*headA;
	// t_list	*headB;

	// headA = NULL;
	// headB = NULL;
	int	*tab;
	int i;
	i = 0;
	if (ac > 1)
	{
		tab = ft_parse(av, &i);
		if (tab)
		{
			int j = 0;
			while (j < i)
			{
				printf("%d ", tab[j]);
				j++;
			}
		printf("\n");
		free(tab);
		}		
	}
	return (0);
}
