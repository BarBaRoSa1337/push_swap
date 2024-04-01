/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:07:56 by achakour          #+#    #+#             */
/*   Updated: 2024/04/01 23:30:52 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

 #include <limits.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>

typedef struct t_push
{
    int            data;
    struct  t_push  *next;
}           t_push;

void    rra_rrb_rrr(t_push **stack, char *flag);
void    ra_rb_rr(t_push **stack, char *flag);
void    rr_rrr(t_push **stack_a, t_push **stack_b, char *flag);
void    sa_sb(t_push **stack, char *flag);
void    pa_pb(t_push **a, t_push **b, char *flag);
int     is_lis(int *arr, int len,int n);

void    select_move1(t_push **stack_a, t_push **stack_b, int *pos);
void    select_move2(t_push **stack_a, t_push **stack_b, int *pos);
void    select_move3(t_push **stack_a, t_push **stack_b, int *pos);
void   stack_recovery(t_push **stack_a, t_push **stack_b);
void	ft_lstdelone(t_push **lst);
int     *get_min(t_push *stack);
int     find_max(int *arr, int len);
int     *ft_fill_arr(t_push *lst);
void	ft_lstadd_front(t_push **lst, t_push *new);
void    stack_recovery(t_push **stack_a, t_push **stack_b);
int     select_cheapest(t_push *stack_a, t_push *stack_b, int b_len, int a_len);
void    fix_lst(t_push **stack, int len);
int     *count_push_price(t_push *stack_a, t_push *stack_b, int n, int target, int b_len);
int     detect_target(int *arr, int n,int a_len);
void find_cheapest_in_a(t_push *stack, int **cheap, int target, int a_len);
void    rotate_half_stack(t_push **stack, int len, char *flag);
ssize_t *lst_weight(t_push *stack, int len);
int	is_valid_args(int ac, char **ar);
int     check_doubles(int ac, char **ar);
void    ft_putchar(char *flag);
t_push    *get_args(int ac, char **ar);
void	ft_lstclear(t_push **lst);
void	ft_lstadd_back(t_push **lst, t_push *new);
int	    ft_lstsize(t_push *lst);
t_push	*ft_lstnew(int content);
int    *ft_lis(t_push *lst, int *len);
char	**ft_split(char const *s, char c);
t_push    *find_last_node(t_push *stack);
int     *ft_fill_arr(t_push *lst);
 
#endif
