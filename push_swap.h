/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:07:56 by achakour          #+#    #+#             */
/*   Updated: 2024/04/21 14:35:45 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_push
{
	int				data;
	struct t_push	*next;
}					t_push;

void				rra_rrb_rrr(t_push **stack, char *flag);
void				ra_rb_rr(t_push **stack, char *flag);
void				rr_rrr(t_push **stack_a, t_push **stack_b, char *flag);
void				sa_sb(t_push **stack, char *flag);
void				pa_pb(t_push **a, t_push **b, char *flag);
int					is_lis(int *arr, int len, int n);
void				select_move1(t_push **stack_a, t_push **stack_b, int *pos);
void				select_move2(t_push **stack_a, t_push **stack_b, int *pos);
void				select_move3(t_push **stack_a, t_push **stack_b, int *pos);
void				stack_recovery(t_push **stack_a, t_push **stack_b,
						int a_len, int b_len);
int					push_node(t_push **stack_a, t_push **stack_b, int a_len,
						char *flag);
void				ft_lstdelone(t_push **lst);
int					*get_min(t_push *stack);
int					ft_strlen(char *str);
int					find_max_small(int *arr, int len);
int					find_max_big(int *arr, int len);
int					is_sorted(t_push *stack);
int					is_descending(t_push *stack);
void				ft_perror(t_push **lst);
int					ft_isdigit(int c);
int					*ft_fill_arr(t_push *lst);
void				ft_lstadd_front(t_push **lst, t_push *new);
int					select_cheapest(t_push *stack_a, t_push *stack_b, int b_len,
						int a_len);
void				fix_lst(t_push **stack, int len);
int					*count_push_price(t_push *stack_a, t_push *stack_b, int n,
						int a_len);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
int					detect_target(int *arr, int n, int a_len);
void				find_cheapest_in_a(t_push *stack, int **cheap, int target,
						int a_len);
void				rotate_half_stack(t_push **stack, int len, char *flag);
char				**get_chars(int ac, char **ar);
char				**ft_split(char const *s, char c);
int					is_valid_args(char **ar);
int					check_doubles(char **ar);
void				ft_putchar(char *flag);
t_push				*get_args(char **ar);
void				ft_lstclear(t_push **lst);
void				ft_lstadd_back(t_push **lst, t_push *new);
int					ft_lstsize(t_push *lst);
t_push				*ft_lstnew(int content);
int					*ft_lis(t_push *lst, int *len);
int					*ft_fill_arr(t_push *lst);
void				ft_freebuff(char **buff);
int					is_all_spaces(char *str);

#endif
