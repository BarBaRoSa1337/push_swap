/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:07:56 by achakour          #+#    #+#             */
/*   Updated: 2024/02/12 13:42:45 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

 #include <stdio.h>
 #include <limits.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>

typedef struct push
{
    int            data;
    struct  push  *next;
}           push;

void    rra_rrb_rrr(push **stack, push **last,char *flag);
void    ra_rb_rr(push **stack, push **last,char *flag);
void    sa_sb_ss(push *stack, char *flag);
void    pa_pb(push **a, push **b, char *flag);

int     ft_double_numbers(int *arr, int n, unsigned int len);
int     ft_is_all_digit(int ac, char **ar);
int     ft_check_dobles_limits(int ac, char **ar);
push    *get_args(int ac, char **ar);
void	ft_lstclear(push **lst);

void	ft_lstadd_back(push **lst, push *new);
// void	ft_lstdelone(push *lst);
int	    ft_lstsize(push *lst);
push	*ft_lstnew(int content);
// ah torta9 lbarod
int *ft_count_sort_indexes(push *stack, int n);
char	**ft_split(char const *s, char c);
void    filter_lst(push **stack_a, push **stack_b);
push    *find_last_node(push *stack);
int    *ft_lis(push *lst, int len);
int    *ft_fill_arr(push *lst);

#endif
