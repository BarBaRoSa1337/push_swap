/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/03/13 14:37:57 by achakour         ###   ########.fr       */
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

void    sort_three(push **stack_a)
{
    push    *head;
    int     *min;
    int     max;

    head = *stack_a;
    min = get_min(head);
    max = find_max(ft_fill_arr(head), ft_lstsize(*stack_a));
    if (head->data == max)
    {
        ra_rb_rr(stack_a, "ra");
    }
    else if (head->next->data == max)
    {
        rra_rrb_rrr(stack_a, "rra");
    }
    head = *stack_a;
    if (head->data > head->next->data)
    {
        sa_sb(stack_a, "sa");
    }
    free (min);
}

void    push_node_to_b(push **stack_a, push **stack_b, int min)
{
    push    *head;
    int     pos[2];

    head = *stack_a;
    while (head && head->data != min)
    {
        pos[0]++;
        head = head->next;
    }
    pos[1] = ft_lstsize(*stack_a) - pos[0];
    if (pos[0] > pos[1])
    {
        while (pos[1] > 0 && pos[1]--)
        {
            rra_rrb_rrr(stack_a, "rra");
        }
    }
    else
    {
        while (pos[0] > 0 && pos[0]--)
        {
            ra_rb_rr(stack_a, "ra");
        }
    }
    pa_pb(stack_a, stack_b, "pb");
}

void    sort_five(push **stack_a, push **stack_b)
{
    push    *head;
    int     *min;
    int     len;

    if (!stack_a || !*stack_a || !stack_b || !*stack_b)
        return ;
    head = *stack_a;
    *stack_b = NULL;
    len = ft_lstsize(head);
    while (len > 3)
    {
        min = get_min(head);
        push_node_to_b(stack_a, stack_b, min[0]);
        head = *stack_a;
        free (min);
        len--;
    }
    len = ft_lstsize(*stack_b);
    sort_three(stack_a);
    while (len)
    {
        stack_recovery(stack_a, stack_b);
        --len;
    }
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
    while (tmp && lis)
    {
        head = *stack_a;
        if (!is_lis(lis, stack_len, head->data))
        {
            pa_pb (stack_a, stack_b, "pb");
        }
        rra_rrb_rrr(stack_a, "rra");
        --tmp;
    }
    stack_len = ft_lstsize(*stack_b);
    while (stack_len--)
        stack_recovery(stack_a, stack_b);
    free (lis);
}

int main(int ac, char **ar)
{
    int         stack_len;
    push        *stack_b;
    push        *stack_a;
    ssize_t     *weight;

    //if (!ft_is_all_digit(ac, ar) || !ft_check_dobles_limits(ac, ar))
    //     perror("ERROR");
    stack_a = get_args(ac, ar);
    if (ac == 1 || is_sorted(stack_a))
        return (ft_lstclear(&stack_a), 0);
    stack_len = ft_lstsize(stack_a);
    if (stack_len == 3)
        sort_three(&stack_a);
    else if (stack_len == 5)
        sort_five(&stack_a, &stack_b);
    else
    {
        weight = lst_weight(stack_a, stack_len);
        if (weight[0] > weight[1])
            rotate_half_stack(&stack_a, stack_len, "ra");
        push_swap(&stack_a, &stack_b);
        fix_lst(&stack_a, ft_lstsize(stack_a));
        free (weight);
    }
    return (ft_lstclear(&stack_a), 0);
}

