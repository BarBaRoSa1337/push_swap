/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_recovery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:35:28 by achakour          #+#    #+#             */
/*   Updated: 2024/03/04 13:37:05 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    select_move3(push **stack_a, push **stack_b, int *pos)
{

    if (pos[1] == 1)
    {
        while (pos[0] > 0 && pos[0]--)
            rra_rrb_rrr(stack_b, "rrb");
    }
    else if (pos[1] == -1)
    {
        while (pos[0] > 0 && pos[0]--)
            ra_rb_rr(stack_b, "rrb");
    }
    if (pos[3] == 1)
    {
        while (pos[2] > 0 && pos[2]--)
            rra_rrb_rrr(stack_a, "rra");
    }
    else if (pos[3] == -1)
    {
        while (pos[2] > 0 && pos[2]--)
        {
            ra_rb_rr(stack_a, "rrb");
        }
    }
    pa_pb(stack_a, stack_b, "pb");
}

void    select_move2(push **stack_a, push **stack_b, int *pos)
{
    while (pos[0] > 0 && pos[2] > 0 && pos[0]-- && pos[2]--)
    {
        rr_rrr(stack_a, stack_b, "rr");
    }
    while (pos[0] > 0 && pos[0]--)
    {
        ra_rb_rr(stack_b, "rb");
    }
    while (pos[2] > 0 && pos[2]--)
    {
        ra_rb_rr(stack_a, "ra");
    }
    pa_pb(stack_a, stack_b, "pb");
}

void    select_move1(push **stack_a, push **stack_b, int *pos)
{
    if (pos[1] == 1 && pos[3] == 1)
    {
        while (pos[0] > 0 && pos[2] > 0 && pos[0]-- && pos[2]--)
        {
            rr_rrr(stack_a, stack_b, "rrr");
        }
        while (pos[0] > 0 && pos[0]--)
        {
            rra_rrb_rrr(stack_b, "rrb");
        }
        while (pos[2] > 0 && pos[2]--)
        {
            rra_rrb_rrr(stack_a , "rra");
        }
        pa_pb(stack_a, stack_b, "pb");
    }
    else if (pos[1] == -1 && pos[3] == -1)
    {
       select_move2(stack_a, stack_b, pos);
    }
    else
    {
        select_move3(stack_a, stack_b, pos);
    }
}

void   stack_recovery(push **stack_a, push **stack_b)
{
    push    *head;
    int     *pos;
    int     a_len;
    int     b_len;
    int     target;
    int     index;

    head = *stack_b;
    a_len = ft_lstsize(*stack_a);
    b_len = ft_lstsize(*stack_b);
    index = select_cheapest(*stack_a, *stack_b, b_len, a_len);
    while (head->next && index--)
        head = head->next;
    target = detect_target(ft_fill_arr(*stack_a), head->data, a_len);
    pos = count_push_price(*stack_a, *stack_b, head->data, target, b_len);
    select_move1(stack_a, stack_b, pos);
    free (pos);
}
