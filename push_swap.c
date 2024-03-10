/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/03/10 12:26:23 by achakour         ###   ########.fr       */
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
    
    while (head && head->next && head->data < head->next->data)
        head = head->next;
    if (!head->next)
        return (1);
    return (0);
}

void    push_swap(push **stack_a, push **stack_b)
{
    int     stack_len;
    int     tmp;
    push    *head;
    int     *lis;

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
        rra_rrb_rrr(stack_a, "rra");
    }
    stack_len = ft_lstsize(*stack_b);
    while (stack_len--)
        stack_recovery(stack_a, stack_b);
    free (lis);
}

int main(int ac, char **ar)
{
    push    *stack_a;
    push    *stack_b;
    // ssize_t     *weight;
    // int     stack_len;

    // if (!ft_is_all_digit(ac, ar) || !ft_check_dobles_limits(ac, ar))
    //     perror("ERROR");
    // printf("!");
    stack_b = NULL;
    stack_a = get_args(ac, ar);
    // stack_len = ft_lstsize(stack_a);
    // weight = lst_weight(stack_a, stack_len);
    // if (weight[0] > weight[1])
    //     rotate_half_stack(&stack_a, stack_len, "rra");
    push_swap(&stack_a, &stack_b);
    fix_lst(&stack_a, ft_lstsize(stack_a));
    // rra_rrb_rrr(&stack_a, "rra");
    // rra_rrb_rrr(&stack_a, "rra");
    
    // pa_pb(&stack_a, &stack_b, "pa");
    
    // rra_rrb_rrr(&stack_a, "rra");
    // pa_pb(&stack_a, &stack_b, "pa");
    
    // rra_rrb_rrr(&stack_a, "rra");
    // pa_pb(&stack_a, &stack_b, "pb");
    // pa_pb(&stack_a, &stack_b, "pb");
    // rra_rrb_rrr(&stack_a, "rra");
    // rra_rrb_rrr(&stack_a, "rra");
    // printf("is sorted %d\n", is_sorted(stack_a));
    
    print_stack(stack_a);
    // free (weight);
    ft_lstclear(&stack_a);
}

