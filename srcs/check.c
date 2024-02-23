/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:09:07 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/23 10:54:27 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_space(char *str)
{
	int empty;

	empty = 0;
	if (!str)
	{
		return (1);
	}
	if (ft_strcmp(str, "") == 0)
		return (printf("Error\n"), 1);
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
		return (printf("Error\n"), 1);
	return (0);
}

static int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_sign(str[i]) && ((!ft_isdigit(str[i + 1]))
				|| (str[i + 1] == '\0')))
			return (printf("Error\n"), 1);
		if ((check_sign(str[i])) && (ft_isdigit(str[i - 1])))
			return (printf("Error\n"), 1);
		if (!check_sign(str[i]) && !ft_isdigit(str[i]) && str[i] != ' ')
			return (printf("Error\n"), 1);
		i++;
	}
	return (0);
}

static char	**input_tab(char **tab, char *str)
{
	tab = ft_split(str, ' ');
	free(str);
	if (!tab)
		return (free(str), NULL);
	return (tab);
}

char	**join_arg(char **av)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**tab;

	str = NULL;
	tab = NULL;
	i = 0;
	while (av[++i])
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
		if (check_char(av[i]))
			return (free(tmp), NULL);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
	}
	return (input_tab(tab, str));
}

int	check_doublon(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (printf("Error\ndoublon\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}
