/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/02/11 19:05:44 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_down_and_push(push **stack_a, push **stack_b)
{
    int pos;
    int i;

    i = 0;
    pos = find_node(*stack_b);
    while (i < pos + 1)
    {
        ra_rb_rr(stack_a, "rb");
        pa_pb(&stack_a, &stack_b, "pb");
    }
}

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

void    filter_lst(push **stack_a, push **stack_b)
{
    int     stack_len;
    push    *last;
    int     *lis;

    lis = ft_lis(*stack_a);
    stack_len = ft_lstsize(*stack_a);
    last = find_last_node(*stack_a);
    while (stack_len--)
    {
        if (!is_lis(lis, last->data))
            pa_pb(&stack_a, &stack_b, "pa");
        ra_rb_rr(*stack_a, "ra");
    }
    free (lis);
    lis = ft_count_sort_indexes(stack_a);
    stack_len = ft_lstsize(stack_b);
    while (stack_len--)
    {
        if (lis[0] >= lis[1])
            
        else
            
    }
}

int main(int ac, char **ar)
{
    push    *stack_a;
    push    *stack_b;
    int     stack_len;

    if (!ft_check_dobles_limits(ac, ar) || !ft_is_all_digit(ac, ar) || ac == 1)
        ft_perror();
    stack_a = get_args(ac, ar);
    stack_len = ft_lstsize(stack_a);
    if (ft_is_sorted(stack_a))
        return (0);
    else if (is_descending(stack_a))
        //rotate the stack
    else if (stack_len == 3 || stack_len == 5)
        sort_small_stack(&stack_a, &stack_b);
    else if (stack_len == 2)
        ra_rb_rr(stack_a, "ra");
    else
        
    return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
