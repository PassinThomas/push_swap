/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/24 15:35:24 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tmp_b;
	int		nb;

	nb = 0;
	head_a = NULL;
	head_b = NULL;
	tmp_b = NULL;
	if (ac > 1)
	{
		if (!insert_list(av, &head_a, &nb))
			return (ft_clean(&head_a), 1);
		if (nb == 1)
			return (ft_clean(&head_a), 1);
		else if (nb == 2)
			sort_2(&head_a);
		else if (nb == 3)
			sort_3(&head_a);
		else
			sort_all(&head_a, &head_b, tmp_b);
		ft_clean(&head_a);
	}
	return (0);
}
