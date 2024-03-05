/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/03/05 08:54:36 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// size_t *lst_weight(push *stack, int len)
// {
//     ssize_t *weight;
//     int tmp;
//     int i;

//     i = 0;
//     weight = malloc(sizeof(size_t) * 2);
//     if (!weight)
//         return (NULL);
//     while (i < (len / 2) && weight[0] < LONG_MAX)
//     {
//         weight[0] += stack->data;
//         stack = stack->next;
//         ++i;
//     }
//     while (stack && weight[1] < LONG_MAX)
//     {
//         weight[1] += stack->data;
//         stack = stack->next;
//     }
//     return (weight);
// }

int is_lis(int *arr, int len, int n)
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
    int *tmp;
    int i;

    tmp = malloc(sizeof(int) * 2);
    if (!tmp)
        return (NULL);
    i = 1;
    tmp[0] = stack->data;
    tmp[1] = i;
    stack = stack->next;
    while (stack)
    {
        if (stack->data < tmp[0])
        {
            tmp[0] = stack->data;
            tmp[1] = i;
        }
        stack = stack->next;
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
        return ;
    tmp = get_min(*stack);
    head = *stack;
    while (i < len && head->data != tmp[0])
    {
        if (tmp[1] < len / 2)
            ra_rb_rr(stack, "ra");
        else
            rra_rrb_rrr(stack, "rra");
        head = *stack;
        ++i;
    }
    free (tmp);
}
