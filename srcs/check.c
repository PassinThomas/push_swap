/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:09:07 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/21 20:24:44 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_space(char *str)
{
	int empty;

	empty = 0;
	if (!str)
		return (1);
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
			empty = 1;
		else if (*str != ' ' || *str != '\t' || *str != '\n')
		{
			empty = 0;
			break ;
		}
		str++;
	}
	if (empty == 1)
		return (1);
	return (0);
}

char	**join_arg(char **av)
{
	int	i;
	char	*str;
	char	*tmp;
    char    **tab;

	str = NULL;
	tab = NULL;
	i = 1;
	while (av[i])
	{
		if (check_space(av[i]))
		{
			if (str)
				free(str);
			return (NULL);
		}
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
    tab = ft_split(str, ' ');
	return (tab);
}