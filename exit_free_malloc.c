#include "push_swap.h"

//function exit 
void ft_exit(t_tab **my_tab,t_lists **t,int type)
{
	write(1,"Error\n",6);
	if (type)
		ft_free(my_tab,t);
	exit(1);
}

//function malloc
void ft_malloc(t_tab **my_tab,t_lists **t,int n)
{
	if(!(*my_tab = malloc(sizeof(t_tab))))
		ft_exit(my_tab,t,1);
	if(!(*t = malloc(sizeof(t_lists))))
		ft_exit(my_tab,t,1);
	/*if(!((*t)->a = malloc(sizeof(t_list))))
		ft_exit(my_tab,t,1);
	if(!((*t)->b = malloc(sizeof(t_list))))
		ft_exit(my_tab,t,1);*/
	if(!((*my_tab)->tab = malloc(sizeof(int) * n)))
			ft_exit(my_tab,t,1);
	(*t)->a = NULL;
	(*t)->b = NULL;
	(*t)->max = 0;
	(*t)->med = 0;
	(*t)->min = 0;
	(*my_tab)->count = n;
	(*t)->count_a = 0;
	(*t)->count_b = 0;
}

// function free
void ft_free(t_tab **my_tab,t_lists **t)
{
	if (!*t && !*my_tab)
	{
		if (!(*t)->a)
		{
			while ((*t)->a)
			{
				free((*t)->a);
				(*t)->a = (*t)->a->next;
			}
		}
		if (!(*t)->b)
		{
			while ((*t)->b)
			{
				free((*t)->b);
				(*t)->b = (*t)->b->next;
			}
		}
		free(t);
		free((*my_tab)->tab);
		free(*my_tab);
	}
}

