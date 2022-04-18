#include "push_swap.h"

//functin de sort
void sort_2(t_list **a)
{
	
	if ((*a)->data > (*a)->next->data)
		*a = ft_ra(*a);
	
}
void sort_3(t_list **a)
{
	int i;
	int j;
	int k;

	i = (*a)->data;
	j = (*a)->next->data;
	k = (*a)->next->next->data;
	
	if (i > j && j > k)
	{
		*a = ft_ra(*a);
		*a = ft_sa(*a);
	}
	else if (i > k && k > j)
	 	*a = ft_ra(*a);
	else if (k > i && i >j)
	 	*a = ft_sa(*a);
	else if (j > k && k > i)
	{
		*a = ft_sa(*a);
		*a = ft_ra(*a);
	}
	else if (j > i && i > k)
		*a = ft_rra(*a);
}
void sort_simple(t_tab *my_tab)
{
	int i;
	int	tmp;
	int j;

	i = 1;
	while(i < my_tab->count)
	{
		tmp = my_tab->tab[i];
		j = i -1;
		while(j >= 0 && tmp < my_tab->tab[j])
		{
			my_tab->tab[j+1] = my_tab->tab[j];		
			j--;
		}
		my_tab->tab[j + 1] = tmp;
		i++;
	}
}
void sort_100(t_tab *my_tab,t_lists **t)
{
	
	int j;
	int k;
	int n;

	j = 0;
	k = 1;
	n = my_tab->count;
	sort_simple(my_tab);
		
	while (k < 4)
	{
		
		j = 0;
		while(j < n/4)
		{
			//khasna mazal nasta3mlo rra o sa
			if ((*t)->a->data < my_tab->tab[k * (n / 4)])
			{
				ft_pb(t);
				j++;
				
			}
			else
				(*t)->a = ft_ra((*t)->a);
			
		}
		k++;
	}


	sort_25(t);
	
	
	while((*t)->b->data >= my_tab->tab[3 * (n / 4)])
		ft_pa(t);
	t_list *tmp;
	int max;
	int i;
	int position;

	while((*t)->count_b > 1)
	{
		tmp = (*t)->b;
		max = (tmp)->data;
		i = 0;
		while(tmp)
		{
			if(tmp->data >= max)
			{
				max = tmp->data;
				position = i;
			}
			i++;
			tmp = tmp->next;
		}
		if (position < (*t)->count_b / 2)
		{
			while(position)
			{
				(*t)->b = ft_rb((*t)->b);
				position--;
			}
		}
		else
		{
			while((*t)->count_b - position)
			{
				(*t)->b = ft_rrb((*t)->b);
				position++;
			}
		}
		ft_pa(t);
		
	}
	ft_pa(t);
}
