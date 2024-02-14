/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/14 17:51:49 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_count_sort_indexes(push *stack, int n)
{
    int  *i;
    i = malloc(sizeof(int) * 2);
    if (!i)
        return (NULL);
    while (stack && stack->data != n)
    {
        i[0] += 1;
        stack = stack->next;
    }
    if (stack->data == n)
    {
        stack = stack->next;
        i[0] += 1;
    }
    while (stack)
    {
        i[1] += 1;
        stack = stack->next;
    }
    return (i);
}
