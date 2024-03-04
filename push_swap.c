/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/03/04 11:02:56 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(push **stack_a, push **stack_b)
{
    int     stack_len;
    int     tmp;
    push    *last;
    push    *head;
    int     *lis;

    if (!stack_a || !*stack_a)
        return ;
    head = *stack_a;
    stack_len = ft_lstsize(head);
    tmp = stack_len;
    lis = ft_lis(head, &stack_len);
    while (tmp--)
    {
        head = *stack_a;
        if (!is_lis(lis, stack_len, head->data))
        {
            pa_pb (stack_a, stack_b, "pa");
        }
        rra_rrb_rrr(stack_a, &last, "rra");
    }
    stack_len = ft_lstsize(*stack_b);
    while (stack_len--)
        stack_recovery(stack_a, stack_b);
    // fix_lst(stack_a, ft_lstsize(*stack_a));
    free (lis);
}

int main(int ac, char **ar)
{
    push    *stack_a;
    push    *stack_b;
    // size_t     *weight;
    // int     stack_len;

    // if (!ft_check_dobles_limits(ac, ar) || !ft_is_all_digit(ac, ar) || ac == 1)

    stack_b = NULL;
    stack_a = get_args(ac, ar);
    // stack_len = ft_lstsize(stack_a);
    // weight = lst_weight(stack_a, stack_len);
    // if (weight[0] > weight[1])
    //     rotate_half_stack(&stack_a, stack_len, "rra");
    push_swap(&stack_a, &stack_b);
    // return (free (weight), ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
 