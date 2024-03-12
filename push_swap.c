/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/03/11 09:50:21 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(push *stack)
{
    push *head;
    head = stack;
    while (head)
    {
        printf("||%d||\n", head->data);
        head = head->next;
    }
}

int is_sorted(push *stack)
{
    push *head = stack;
    int len = ft_lstsize(stack) - 1;
    
    while (head && head->next && head->data < head->next->data)
    {
        head = head->next;
        --len;
    }
    if (len == 0)
        return (1);
    return (0);
}

void    push_swap(push **stack_a, push **stack_b)
{
    int     stack_len;
    push    *head;
    int     *lis;
    int     tmp;

    if (!stack_a || !*stack_a)
        return ;
    head = *stack_a;
    stack_len = ft_lstsize(head);
    tmp = stack_len;
    lis = ft_lis(head, &stack_len);
    while (tmp-- && lis)
    {
        head = *stack_a;
        if (!is_lis(lis, stack_len, head->data))
        {
            pa_pb (stack_a, stack_b, "pa");
        }
        ra_rb_rr(stack_a, "ra");
    }
    stack_len = ft_lstsize(*stack_b);
    while (stack_len-- && stack_len > 0)
        stack_recovery(stack_a, stack_b);
    free (lis);
}

int main(int ac, char **ar)
{
    push    *stack_a;
    push    *stack_b;
    ssize_t     *weight;
    int     stack_len;

    // if (!ft_is_all_digit(ac, ar) || !ft_check_dobles_limits(ac, ar))
    //     perror("ERROR");
    stack_b = NULL;
    stack_a = get_args(ac, ar);
    stack_len = ft_lstsize(stack_a);
    weight = lst_weight(stack_a, stack_len);
    if (weight[0] > weight[1])
        rotate_half_stack(&stack_a, stack_len, "ra");
    push_swap(&stack_a, &stack_b);
    fix_lst(&stack_a, ft_lstsize(stack_a)); 
    // print_stack(stack_a);
    free (weight);
    return (ft_lstclear(&stack_a), 0);
}

