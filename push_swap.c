/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/02/17 10:06:45 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    stack_recovery(push **stack_a, push **stack_b, int len)
// {
//     int max;
//     int *pos;
//     push    *last;
//     while (len)
//     {
//         last = find_last_node(*stack_a);
//         max = ft_max(*stack_b);
//         if (last->data < max)
//         {
//             pos = count_push_price(*stack_b, max);
//             if (pos[0] < pos[1])
//                 move_up_down_push(stack_a, stack_b, max,'d');
//             else
//                 move_up_down_push(stack_a, stack_b, max,'u');
//             free (pos);
//             len++;
//         }
//         else
//         {
//             rra_rrb_rrr(stack_a, &last, "rra");
//             --len;
//         }
//     }
// }

void    stack_recovery(push **stack_a, push **stack_b, int len)
{
    push *a = *stack_a;
    push *b = *stack_b;
    push    *a_last;
    push    *b_last;
    int a_len = ft_lstsize(a);
    int b_len = ft_lstsize(b);

    while (a_len)
    {
        a_last = find_last_node(a);
        if (a_last->data < b_last->data)
        {
            pa_pb(stack_a, stack_b, "pb");
            a_len++;
        }
        else if
        {
            
        }
    }
}
void    filter_lst(push **stack_a, push **stack_b)
{
    int     stack_len;
    int     tmp;
    push    *last;
    push    *head;
    int     *lis;

    head = *stack_a;
    stack_len = ft_lstsize(head);
    tmp = stack_len;
    lis = ft_lis(head, &stack_len);
    while (tmp--)
    {
        head = *stack_a;
        last = find_last_node(head);
        if (!is_lis(lis, stack_len, last->data))
        {
            pa_pb(stack_a, stack_b ,"pa");
        }
        ra_rb_rr (stack_a, "ra");
    }
    free (lis);
}

int main(int ac, char **ar)
{
    push    *stack_a;
    push    *stack_b;
    int     stack_len;

    // if (!ft_check_dobles_limits(ac, ar) || !ft_is_all_digit(ac, ar) || ac == 1)
    //     ft_perror();
    stack_b = NULL;
    stack_a = get_args(ac, ar);
    stack_len = ft_lstsize(stack_a);
    // if (ft_is_sorted(stack_a))
    //     return (0);
    // else if (stack_len == 2)
    //     ra_rb_rr(stack_a, "ra");
    // else
    // push_swap(&stack_a, &stack_b);
    filter_lst(&stack_a, &stack_b);
    // stack_recovery(&stack_a, &stack_b, stack_len);
    return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
 