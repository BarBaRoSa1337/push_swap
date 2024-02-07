/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/02/05 18:17:26 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    *ft_lst_sort(push *stack_a, push *stack_b)
{
    int i;
    int *seq;
    int *up_down;

    i = 0;
    seq = ft_lsi(stack_a);
    while (stack_a)
    {
        if (seq[i] == stack_a->data)
            ++i;
        else
        {
            up_down = ft_count_sort_indexes(stack_a, stack_a->data);
            if (up_down[0] > up_down[1])
                move_down_and_push(stack_a, stack_a->data);
            else
                move_up_and_push(stack_a, stack_a->data);
        }
        stack_a = stack_a->next;
    }
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
        // reverse the list
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
