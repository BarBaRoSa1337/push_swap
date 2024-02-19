/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/17 15:13:30 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_half_stack(push **stack, int len, char *flag)
{
    int     i;
    push    *last;

    i = 0;
    while (i < (len / 2))
    {
        rra_rrb_rrr(stack, &last, flag);
        ++i;
    }
}

size_t *lst_weight(push *stack, int len)
{
    size_t *weight;
    int tmp;
    int i;

    i = 0;
    weight = malloc(sizeof(size_t) * 2);
    if (!weight)
        return (NULL);
    while (i < (len / 2) && weight[0] < ULONG_MAX )
    {
        weight[0] += stack->data;
        stack = stack->next;
        ++i;
    }
    while (stack && weight[1] < ULONG_MAX)
    {
        weight[1] += stack->data;
        stack = stack->next;
    }
    return (weight);
}

int is_lis(int *arr, int len,int n)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (arr[i] == n)
            return (1);
        ++i;
    }
    return (0);
}

int ft_max(push *stack)
{
    int tmp;

    if (!stack)
        return (0);
    tmp = stack->data;
    while (stack)
    {
        if (stack->data > tmp)
            tmp = stack->data;
        stack = stack->next;
    }
    return (tmp);   
}

int *count_push_price(push *stack, int n)
{
    int *pos;

    pos = malloc(sizeof(int) * 2);
    while (stack && stack->data != n)
    {
        pos[0] += 1;
        stack = stack->next;
    }
    if (stack->data = n)
    {
        pos[0] += 1;
        stack = stack->next;
    }
    while (stack)
    {
        pos[1] += 1;
        stack = stack->next;
    }
    return (pos);
}

void    move_up_down_push(push **stack_a, push **stack_b, int n, char flag)
{
    push    *last;

    last = find_last_node(*stack_b);
    if (flag == 'u')
    {
        while (last->data != n)
            rra_rrb_rrr(stack_b, &last, "rrb");
        if (last->data == n)
            pa_pb(stack_a, stack_b, "pb");
    }
    if (flag == 'd')
    {
        while (last->data != n)
        {
            ra_rb_rr(stack_b, "rb");
            last = find_last_node(*stack_b);
        }
        if (last->data == n)
            pa_pb(stack_a, stack_b, "pb");
    }
}
