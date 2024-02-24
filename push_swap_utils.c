/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/23 11:12:23 by achakour         ###   ########.fr       */
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

int ft_min(int *arr, int len, int *index)
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
    i = 0;
    while (arr[i])
    {
        if (arr[i] == min)
            *index = i;
        ++i;
    }
    return (min);
}


void    fix_lst(push **stack, int len)
{
    int tmp[2];
    int i;
    push    *head;
    push    *lst;

    i = 0;
    head = *stack;
    tmp[0] = head->data;
    while (head)
    {
        if (head->data < tmp[0])
        {
            tmp[0] = head->data;
            tmp[1] = i;
        }
        head = head->next;
        ++i;
    }
    head = *stack;
    lst = *stack;
    while (lst && head->data != tmp[0])
    {
        if (tmp[1] <= len / 2)
            ra_rb_rr(stack, "ra");
        else
            rra_rrb_rrr(stack, NULL, "rra");
        head = *stack;
        lst = lst->next;
    }
}

void find_cheapest_in_a(push *stack, int **cheap, int target ,int a_len)
{
    (*cheap)[2] = 0;
    while (stack && stack->data != target)
    {
        (*cheap)[2] += 1;
        stack = stack->next;
    }
    if (stack->next && stack->next->data == target)
        (*cheap)[2] += 1;
    (*cheap)[3] = a_len - (*cheap)[2];
    if ((*cheap)[2] < (*cheap)[3])
        (*cheap)[3] = -1;
    else
    {
        (*cheap)[2] = (*cheap)[3];
        (*cheap)[3] = 1;
    }
}

int *count_push_price(push *stack_a, push *stack_b, int n, int *arr, int b_len)
{
    int *pos;
    int target;

    target = put_numbr_inplace(arr, n, ft_lstsize(stack_a));
    pos = malloc(sizeof(int) * 4);
    if (!pos)
        return (NULL);
    pos[0] = 0;
    while (stack_b && stack_b->data != n)
    {
        pos[0] += 1;
        stack_b = stack_b->next;
    }
    if (stack_b->data == n)
        pos[0] += 1;
    pos[1] = b_len - pos[0];
    if (pos[0] < pos[1])
        pos[1] = -1;
    else if (pos[0] > pos[1])
    {
        pos[0] = pos[1];
        pos[1] = 1;
    }
    find_cheapest_in_a(stack_a, &pos, target,ft_lstsize(stack_a));
    return (pos);
}

int select_cheapest(push *stack_a, push *stack_b, int *arr, int b_len)
{
    push    *head;
    int     best[2];
    int     i;
    int     *tmp;

    i = 0;
    head = stack_b;
    while (i < b_len)
    {
        tmp = count_push_price(stack_a, stack_b, head->data, arr ,b_len);
        if (i == 0)
        {
            best[0] = tmp[0] + tmp[2];
            best[1] = i;
        }
        if (tmp[0] + tmp[2] < best[0])
        {
            best[0] = tmp[0] + tmp[2];
            best[1] = i;
        }
        free (tmp);
        head = head->next;
        ++i;
    }
    return(best[0] + 1);
}
