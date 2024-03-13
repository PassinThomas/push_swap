#include "../../includes/push_swap.h"

void    sort_tab(int *tab,int i, int j)
{
    int k;
    int tmp;

    k = 0;
    j = 0;
    while (j < i)
    {
        k = j + 1;
        while (k < i)
        {
            if (tab[j] > tab[k])
            {
                tmp = tab[j];
                tab[j] = tab[k];
                tab[k] = tmp;
            }
            k++;
        }
        j++;
    }
}

void insert_list(char **av, t_stack **headA, int *nb)
{
    int i;
	int j;
    int *tab;

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
        if (i >= 4)
        {
            sort_tab(tab, i, j);
            (*headA)->median = tab[(i / 2) - 1];
        }
        free(tab);
    }
    return;
}
