/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/21 20:19:55 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void ft_free(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  return ;
}

int main(int ac, char **av)
{
	int	i;
	int	j;
	char	**str;
	
	str = NULL;
	i = 0;
	j = 0;
	
	if (ac > 1)
	{
		str = join_arg(av);
		if (!str)
			return (0);
		// while (str[i])
    	// 	{
      	// 		while (str[i][j])
      	// 		{
		// 			write(1, &str[i][j], 1);
		// 			j++;
		// 		}
		// 		i++;
		// 	}
		ft_free(str);
	}
	return (0);
}
