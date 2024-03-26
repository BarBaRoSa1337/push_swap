/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:07:56 by achakour          #+#    #+#             */
/*   Updated: 2024/03/26 14:28:34 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct push
{
	int			data;
	struct push	*next;
}				t_push;

void	sort_five(t_push **stack_a, t_push **stack_b);
void	sort_three(t_push **stack_a);
void			rr_rrr(t_push **stack_a, t_push **stack_b, char *flag);
void			pa_pb(t_push **a, t_push **b, char *flag);
void			rra_rrb_rrr(t_push **stack, char *flag);
void			ra_rb_rr(t_push **stack, char *flag);
void			sa_sb(t_push **stack, char *flag);
int				is_lis(int *arr, int len, int n);

int				ft_strlen(char *str);
int				*get_min(t_push *stack);
int				is_valid_args(int ac, char **ar); 
int				*ft_fill_arr(t_push *lst);
void			ft_lstdelone(t_push **lst);
int				find_max(int *arr, int len);
void			fix_lst(t_push **stack, int len);
int				process_args(t_push **lst, char *buff);
void			ft_lstadd_back(t_push **lst, t_push *new);
void			ft_lstadd_front(t_push **lst, t_push *new);
int				select_cheapest(t_push *stack_a, t_push *stack_b, int b_len,
					int a_len);
void			select_move1(t_push **stack_a, t_push **stack_b, int *pos);
void			select_move2(t_push **stack_a, t_push **stack_b, int *pos);
void			stack_recovery(t_push **stack_a, t_push **stack_b, int a_len, int b_len);
int				*count_push_price(t_push *stack_a, t_push *stack_b, int n, int target);
void			select_move3(t_push **stack_a, t_push **stack_b, int *pos);
void			find_cheapest_in_a(t_push *stack, int **cheap, int target,
					int a_len);
void			rotate_half_stack(t_push **stack, int len, char *flag);
int				detect_target(int *arr, int n, int a_len);
ssize_t			*lst_weight(t_push *stack, int len);
char			**ft_split(char const *s, char c);
int				*ft_lis(t_push *lst, int *len);
t_push			*find_last_node(t_push *stack);
char			*get_args1(int ac, char **ar);
int				*ft_fill_arr(t_push *lst);
void			ft_lstclear(t_push **lst);
ssize_t			ft_atoi(const char *str);
int				ft_lstsize(t_push *lst);
t_push			*ft_lstnew(int content);

#endif
