#include "push_swap.h"

//function de rules
t_list *ft_s(t_list *a)
{
	int tmp;

	if (a == NULL || a->next == NULL)
	return (NULL);

	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
	return a;
}
t_list *ft_sa(t_list *a)
{
	
	write(1,"sa\n",3);
	return (ft_s(a));
}
t_list *ft_sb(t_list *a)
{
	
	write(1,"sb\n",3);
	return (ft_s(a));
}
void	ft_ss(t_list **a,t_list **b)
{
	*a = ft_s(*a);
	*b = ft_s(*b);
	write(1,"ss\n",3);
}

void ft_pa(t_lists **t)
{
	t_list *tmp;

	if ((*t)->b == NULL)
	return ;
	tmp = (*t)->b;
	(*t)->b = ((*t)->b)->next;
	tmp->next = (*t)->a;
	(*t)->a = tmp;
	(*t)->count_b--;
	(*t)->count_a++;

	write(1,"pa\n",3);
}
void ft_pb(t_lists **t)
{
	t_list *tmp;

	if ((*t)->a == NULL)
	return ;
	tmp = (*t)->a;
	(*t)->a = ((*t)->a)->next;
	tmp->next = (*t)->b;
	(*t)->b = tmp;
	(*t)->count_a--;
	(*t)->count_b++;

	write(1,"pb\n",3);
}
t_list *ft_r(t_list *a)
{
	t_list *a1;
	t_list *tmp;

	tmp = a;
	a = a->next;
	a1 = a;
	while (a1->next)
		a1 = a1->next;
	a1->next = tmp;
	tmp->next = NULL;
	return (a);
}
t_list	*ft_ra(t_list *a)
{
	//printf("%d\n",(a)->data);
	if (!a)
	return NULL;
	write(1,"ra\n",3);
	return (ft_r(a));
}

t_list	*ft_rb(t_list *a)
{
	if (!a)
	return NULL;
	write(1,"rb\n",3);
	return (ft_r(a));
}
void  ft_rr(t_list **a,t_list **b)
{
	if (*a || *b)
	return ;
	*a = ft_r(*a);
	*b = ft_r(*b);
	write(1,"rr\n",1);
}

t_list *ft_rr_(t_list *a)
{
	t_list *a1;
	t_list *tmp;

	a1 = a;
	while (a1->next->next)
		a1 = a1->next;
	tmp = a1->next;
	a1->next = NULL;
	tmp->next = a;
	return (tmp);
}
t_list *ft_rra(t_list *a)
{
	if (a == NULL)
		return NULL;
	
	write(1,"rra\n",4);
	return (ft_rr_(a));
}
t_list *ft_rrb(t_list *a)
{
	if (a == NULL)
	return NULL;
	write(1,"rrb\n",4);
	return (ft_rr_(a));
}
void ft_rrr(t_list **a,t_list **b)
{
	if (*a == NULL || *b == NULL)
	return ;
	*a = ft_rr_(*a);
	*b = ft_rr_(*b);
	write(1,"rrr\n",4);
}