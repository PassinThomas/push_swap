/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:09:07 by tpassin           #+#    #+#             */
/*   Updated: 2024/03/15 01:19:55 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_space(char *str)
{
	int	empty;

	empty = 0;
	if (!str)
	{
		return (1);
	}
	if (ft_strlen(str) == 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	while (*str)
	{
		if (*str == ' ')
			empty = 1;
		else if (*str != ' ')
		{
			empty = 0;
			break ;
		}
		str++;
	}
	if (empty == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
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
			return (ft_putstr_fd("Error\n", 2), 1);
		else if ((check_sign(str[i])) && (ft_isdigit(str[i - 1])))
			return (ft_putstr_fd("Error\n", 2), 1);
		else if (!check_sign(str[i]) && !ft_isdigit(str[i]) && str[i] != ' ')
			return (ft_putstr_fd("Error\n", 2), 1);
		i++;
	}
	return (0);
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
		if (check_space(av[i]) || (check_char(av[i])))
		{
			if (str)
				free(str);
			exit (0);
		}
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
	}
	tab = ft_split(str, ' ');
	return (free(str), tab);
}

int	check_doublon(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (ft_putstr_fd("Error\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_parse(char **av, int *i)
{
	char	**str;
	int		*tab;
	long	nbr;

	*i = 0;
	str = join_arg(av);
	if (!str)
		return (NULL);
	while (str[*i])
		(*i)++;
	tab = (int *)malloc(sizeof(int) * (*i));
	if (!tab)
		return (free(tab), NULL);
	*i = -1;
	while (str[++(*i)])
	{
		nbr = ft_atoi(str[*i]);
		if (nbr == 2147483650)
			return (free(tab), ft_free(str), NULL);
		tab[*i] = ft_atoi(str[*i]);
	}
	if (check_doublon(tab, *i))
		return (ft_free(str), free(tab), NULL);
	return (ft_free(str), tab);
}
