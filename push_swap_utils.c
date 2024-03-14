/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/03/13 14:33:49 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_lis(int *arr, int len, int n)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (arr[i] == n)
        {
            return (1);
        }
        ++i;
    }
    return (0);
}

void    rotate_half_stack(push **stack, int len, char *flag)
{
    int     i;

    i = 0;
    while (i < (len / 2))
    {
        rra_rrb_rrr(stack, flag);
        ++i;
    }
}

ssize_t *lst_weight(push *stack, int len)
{
    ssize_t *weight;
    push    *head;
    int     i;

    i = 0;
    head = stack;
    weight = (ssize_t *)malloc(sizeof(ssize_t) * 2);
    if (!weight)
        return (NULL);
    while (i < (len / 2) && weight[0] < LONG_MAX && weight[0] > LONG_MIN)
    {
        weight[0] += head->data;
        head = head->next;
        ++i;
    }
    while (head && i < (len / 2))
    {
        head = head->next;
    }
    while (head && weight[1] < LONG_MAX && weight[1] > LONG_MIN)
    {
        weight[1] += head->data;
        head = head->next;
    }
    return (weight);
}

int *get_min(push *stack)
{
    push    *head;
    int     *tmp;
    int     i;

    tmp = malloc(sizeof(int) * 2);
    if (!tmp)
    {
        return (NULL);
    }
    i = 1;
    head = stack;
    tmp[0] = head->data;
    head = head->next;
    tmp[1] = i;
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
    int     *tmp;
    int     i;

    if (!stack || !*stack)
    {
        return ;
    }
    i = 0;
    head = *stack;
    tmp = get_min(head);
    while (i < len && tmp && head->data != tmp[0])
    {
        if (tmp[1] < len / 2)
        {
            ra_rb_rr(stack, "ra");
        }
        else
        {
            rra_rrb_rrr(stack, "rra");
        }
        head = *stack;
        ++i;
    }
    free (tmp);
}
