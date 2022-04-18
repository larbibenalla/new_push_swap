/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:01:16 by labenall          #+#    #+#             */
/*   Updated: 2022/03/15 18:58:06 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function utilise pluseur fois
int nbr_arg_str(char *s);




//functin atoi
int ft_atoi(t_tab **my_tab,t_lists **t,char *a)
{
	int long long res;
	int s;

	res = 0;
	s = 1;
	if(*a == ' ' || (*a >= 9 && *a <= 13))
		a++;
	if(*a == '-')
	{
		s = -1;
		a++;
	}
	else if (*a == '+')
		a++;
	while (*a)
	{
		if (*a > '9' || *a < '0')
			ft_exit(my_tab,t,1);
		res = res * 10 + *a - '0';
		if (s == 1 && res > 2147483647)
			ft_exit(my_tab,t,1);
		else if (s == -1 && res > 2147483648)
			ft_exit(my_tab,t,1);
		a++;
	}
	return (res * s);
}

//remilre _tab
void cheak_tab(t_tab **my_tab,t_lists **t,int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*my_tab)->tab[i] == (*my_tab)->tab[j])
				ft_exit(my_tab,t,1);
			j++;
		}
		i++;
	}
}

char *ft_strncpy(char *from,char *dest,int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int is_digit_plus_moin(char c)
{
	if (c == '-' || c == '+' || is_digit(c))
		return 1;
	else
		return 0;
}
char **ft_split(t_tab **my_tab,t_lists **t,char *s)
{
	char **res;
	int n;
	int i;
	int j;

	//printf("%s\n",s);
	n = nbr_arg_str(s);
	//printf("%d\n",n);
	j = 0;
	if(!(res = (char **)malloc(sizeof(char *) * (n + 1))))
		ft_exit(my_tab,t,1);
	res[n] = NULL;
	while(*s)
	{
		i = 0;
		while(is_digit_plus_moin(s[i]) /*&& !is_digit_plus_moin(s[i + 1])*/)
			i++;
			
		if (i > 0)
		{
			if(!(res[j] = malloc(sizeof(char) * (i + 1))))
			ft_exit(my_tab,t,1);
			res[j][i] = 0;
			res[j] = ft_strncpy(s,res[j],i);
			j++;
			s = s + i;
		}
		else
			s++;
	}
	return res;
}
void ft_multi_atoi(t_tab **my_tab,t_lists **t,char *s,int **tab)
{
	char **split;
	int n;
	int i;

	n = nbr_arg_str(s);
	i = 0;
	split = ft_split(my_tab,t,s);
	
	while(i < n)
	{
		(*tab)[i] = ft_atoi(my_tab,t,split[i]);
		i++;
	}
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}


void remplire_tab(t_tab **my_tab,t_lists **t,char **av, int ac)
{
	int a;
	int b;
	int c;
	int d;
	int *new_tab;
	int nbr_arg;

	a = 0;
	b = 1;
	d = 0;
	while (a < ac - 1)
	{
		c = 0;
		nbr_arg = nbr_arg_str(av[b]);
		if(!(new_tab = malloc(sizeof(int) * nbr_arg)))
			ft_exit(my_tab,t,1);
		ft_multi_atoi(my_tab,t,av[b],&new_tab);
		while(c < nbr_arg)
		{
			//printf("%d\nd:%d\n",new_tab[c],d);
			(*my_tab)->tab[d] = new_tab[c];
			//printf("%d\n",(*my_tab)->tab[d]);
			c++;
			d++;
		}
		free(new_tab);
		//sleep(1);
		cheak_tab(my_tab,t,d);
		a++;
		b++;
	}
}


t_list	*ft_lstnew(int data)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof (struct s_list));
	if (!t)
		return (NULL);
	t->data = data;
	t->next = NULL;
	return (t);
}

//function de lst
void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*t;

	t = *lst;
	if (*lst == NULL)
	{
		*lst = n;
		return ;
	}
	while (t->next != NULL)
		t = t->next;
	t->next = n;
}


void remplire_stack_a(t_tab **my_tab,t_lists **t,int size)
{
	t_list *n;
	int i = 0;

	while (i < size)
	{
		n = ft_lstnew((*my_tab)->tab[i]);
		ft_lstadd_back(&((*t)->a),n);
		(*t)->count_a++;
		i++;
	}
}

void printList(t_list *ptr) {
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}






//nbr_arg
int nbr_arg_str(char *s)
{
	int res;

	res = 0;
	while(*s)
	{
		if(is_digit(*s) && !is_digit(*(s + 1)))
			res++;
		s++;
	}
	return res;
}
void sort_25(t_lists **t)
{
	t_list *tmp;
	int min;
	int i;
	int position;

	while((*t)->count_a > 3)
	{
		tmp = (*t)->a;
		min = (tmp)->data;
		i = 0;
		while(tmp)
		{
			if(tmp->data <= min)
			{
				min = tmp->data;
				position = i;
			}
			i++;
			tmp = tmp->next;
		}
		if (position < (*t)->count_a / 2)
		{
			while(position)
			{
				(*t)->a = ft_ra((*t)->a);
				position--;
			}
		}
		else
		{
			while((*t)->count_a - position)
			{
				(*t)->a = ft_rra((*t)->a);
				position++;
			}
		}
		ft_pb(t);
	}
	sort_3(&((*t)->a));
}

void sort_10(t_lists **t)
{
	sort_25(t);
	while((*t)->b)
	{
		ft_pa(t);
		(*t)->count_a++;
		(*t)->count_b--;
	}
}

void sort_500(t_tab *my_tab,t_lists *t)
{
	if(my_tab && t)
		{
			
		}
}
int nbr_arg(int ac,char **av)
{
	int res;
	int i;

	i = 1;
	res =0;
	while(i < ac)
	{
		res += nbr_arg_str(av[i]);
		i++;
	}
	return res;
}

//main
int main(int ac,char**av)
{
	t_lists	*t;
	t_tab	*my_tab;
	int		n;

	if(ac >= 2)
	{
		t = NULL;
		my_tab = NULL;
		validation(&my_tab,&t,av,ac);
		n = nbr_arg(ac,av);
		//printf("n %d\n",n);
		ft_malloc(&my_tab,&t,n);	
		remplire_tab(&my_tab,&t,av,ac);
		remplire_stack_a(&my_tab,&t,n);
		
		//printf("b:%d\n",(t)->count_b);
		//printf("a:%d\n",(t)->count_a);
		//printf("%d\n",n);
		if (n == 2)
			sort_2(&t->a);
		else if (n == 3)
			sort_3(&t->a);
		else if (n <= 10)
			sort_10(&t);
		else if(n <= 100)
			sort_100(my_tab,&t);
		else
			sort_500(my_tab,t);

		/*printf("\na\n");
		printList((t)->a);
		printf("\nb\n");
		printList((t)->b);*/
		//sleep(3);
		ft_free(&my_tab,&t);	
	}
		
	return (0);
}