/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/29 09:22:57 by achakour         ###   ########.fr       */
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
    while (i < (len / 2) && weight[0] < ULONG_MAX)
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

int *get_min(push *stack)
{
    int     i;
    int     *tmp;
    push    *head;

    i = 0;
    head = stack;
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
    return (tmp);
}

void    fix_lst(push **stack, int len)
{
    push    *head;
    push    *lst;
    int     *tmp;

    if (!stack || !*stack)
        return ;
    tmp = get_min(*stack);
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
    free (tmp);
}
