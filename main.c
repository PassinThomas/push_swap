/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/23 12:35:26 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_parse(char **av)
{
	int		i;
	char	**str;
	int		*tab;
	int		count;

	count = 0;
	i = 0;
	str = join_arg(av);
	if (!str)
		return (0);
	while(str[count])
		count++;
	tab = (int *)malloc(sizeof(int) * count);
	if (!tab)
		return (free(tab), 0);
	while (str[i])
	{
		if (ft_strcmp(str[i], "") == 0)
			return (printf("Error\n"), ft_free(str), 0);
		tab[i] = ft_atoi(str[i]);
		printf("%d\n", tab[i]);
		i++;
	}
	if (check_doublon(tab, count))
		return (ft_free(str), free(tab),0);
	return (ft_free(str), free(tab), 0);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_parse(av);
	}

	return (0);
}
