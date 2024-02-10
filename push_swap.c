/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/02/10 18:31:09 by achakour         ###   ########.fr       */
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
        if (is_lis(lis, last->data))
        {
            pa_pb(&stack_a, &stack_b, "pa");      
        }
        ra_rb_rr(*stack_a, "ra");
    }
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
    // ft_lstclear(stack_a);
    // ft_lstclear(stack_b);
}
