/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/27 00:50:48 by tpassin          ###   ########.fr       */
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

int	ft_parse(char **av)
{
	int		i;
	char	**str;
	int		*tab;
	long	nbr;

	i = 0;
	str = join_arg(av);
	if (!str)
		return (0);
	while (str[i])
		i++;
	tab = (int *)malloc(sizeof(int) * i);
	if (!tab)
		return (free(tab), 0);
	i = -1;
	while (str[++i])
	{
		nbr = ft_atoi(str[i]);
		if (nbr == 2147483650)
			return (free(tab), ft_free(str), 0);
		tab[i] = ft_atoi(str[i]);
	}
	if (check_doublon(tab, i))
		return (ft_free(str), free(tab), 0);
	return (ft_free(str), free(tab), 1);
}

int main(int ac, char **av)
{
	// t_list	*headA;
	// t_list	*headB;

	// headA = NULL;
	// headB = NULL;
	if (ac > 1)
	{
		if (ft_parse(av))
		{
			// t_list *current = headA;
        	// while (current != NULL)
        	// {
            // 	printf("%d\n", current->content);
            // 	current = current->next;
        	// }
        	// ft_lstclear(&headA, free);
		}
	}
	return (0);
}
