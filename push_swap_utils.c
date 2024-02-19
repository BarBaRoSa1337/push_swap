/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/19 12:49:44 by achakour         ###   ########.fr       */
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
    if (!pos)
        return (NULL);
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

int ft_min(int *arr, int len)
{
    int i;
    int min;

    i = 0;
    min = arr[i];
    while (i < len)
    {
        if (arr[i] < min)
            min = arr[i];
        ++i;
    }
    return (min);
}

int *find_cheapest_in_a(push *stack, int data, int a_len)
{
    int *cheap;
    int i;

    i = 0;
    cheap = malloc(sizeof(int) * 2);
    while (stack && data < stack->data)
    {
        cheap[0] += 1;
        stack = stack->next;
    }
    if (stack->data == data)
    {
        cheap[0] += 1;
        stack = stack->next;
    }
    cheap[1] = a_len - cheap[0];
    return (cheap);
}

int **find_cheapest(push stack_a, push *stack_b, int a_len, int b_len)
{
    int *a;
    int *b;
    int i;

    i = 0;
    while (stack_b)
    {
        b = count_push_price(stack_b, stack_b->data);
        a = find_cheapest_in_a(stack_a, stack_b->data, a_len);
        
        stack_b = stack_b->next;
    }
    free (a);
    free (b);
    return ();
}

void    stack_recovery(push **stack_a, push **stack_b, int *a_moves, int *b_moves, int target)
{
    if (a_moves[0] < a_moves[1])
        move_up_down_push(stack_a, stack_b, target, '');
    else
        move_up_down_push(stack_a, stack_b, target, '');
    put_node_in_place(stack_a, stack_b);
}