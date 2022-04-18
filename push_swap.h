/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:03:06 by labenall          #+#    #+#             */
/*   Updated: 2022/03/15 17:04:07 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

typedef struct s_tab
{
	int *tab;
	int count;
}				t_tab;

typedef struct s_list
{
	int			data;
	struct s_list	*next;
}				t_list;

typedef struct s_lists
{
	int count_a;
	int count_b;
	int min;
	int max;
	int med;
	t_list *a;
	t_list *b;
}				t_lists;


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int is_digit(char c);
void ft_malloc(t_tab **my_tab,t_lists **t,int n);
int nbr_arg_str(char *s);
void ft_exit(t_tab **my_tab,t_lists **t,int type);
void ft_free(t_tab **my_tab,t_lists **t);
void validation(t_tab **my_tab,t_lists **t,char **av,int ac);
t_list *ft_sa(t_list *a);
t_list *ft_sb(t_list *a);
void ft_pa(t_lists **t);
void ft_pb(t_lists **t);
t_list	*ft_ra(t_list *a);
t_list	*ft_rb(t_list *a);
void  ft_rr(t_list **a,t_list **b);
t_list *ft_rra(t_list *a);
t_list *ft_rrb(t_list *a);
void ft_rrr(t_list **a,t_list **b);
void sort_3(t_list **a);
void sort_2(t_list **a);
void sort_10(t_lists **t);
void sort_25(t_lists **t);
void sort_100(t_tab *my_tab,t_lists **t);
void printList(t_list *ptr);
#endif