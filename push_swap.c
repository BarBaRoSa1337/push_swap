/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/02/09 05:22:39 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_lis(int *arr, int n)
{
    int i;

    i = 0;
    while (arr[i])
    {
        if (arr[i] == n)
            return (1);
        ++i;
    }
    return (0);
}

void    filter_lst(push *stack_a, push *stack_b, int *lis)
{
    int     stack_len;
    push    *Last;
    push    *first;
    int     i;

    i = 0;
    first = stack_a;
    stack_len = ft_lstsize(stack_a);
    while (stack_a)
        stack_a = stack_a->next;
    Last = stack_a;
    stack_a = first;
    while (i < stack_len)
    {
        if (is_lis(Last->data))
            pa_pb(first, stack_b, "pa");
        ra_rb_rr(first, "ra");
        stack_a = stack_a->next;
        stack_len--;
    }
}

void    *ft_lst_sort(push *stack_a, push *stack_b)
{
    int i;
    int *seq;
    int *up_down;

    i = 0;
    seq = ft_lsi(stack_a);
    filter_lst(stack_a, stack_b, seq);
    return (free (seq), free (up_down), 0);
}

void    *push_swap(push *stack_a, push *stack_b)
{
    size_t  stack_len;

    stack_len = ft_lstsize(stack_a);
    if (ft_is_sorted(stack_a))
        return ;
    else if (stack_len == 3 || stack_len == 5)
        
    else if (stack_len == 2)
        ra_rb_rr(stack_a, "ra");
    else
        ft_lst_sort(stack_a, stack_b, stack_len);
    // ft_lstclear(stack_a);
}

int main(int ac, char **ar)
{
    push    *stack_a;
    push    *stack_b;

    if (!ft_check_dobles_limits(ac, ar) || !ft_is_all_digit(ac, ar) || ac == 1)
        ft_perror();
    if (ac == 2)
        ar = ft_split(ar[ac - 1], ' ');
    stack_a = get_args(ac, ar);
    if (ac == 2)
        free_buff(ar);
    push_swap(stack_a, stack_b);
}
