/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_push_price.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:14:47 by achakour          #+#    #+#             */
/*   Updated: 2024/02/06 15:59:43 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// size_t  put_number_in_place(push *stack, int n)
// {
//     size_t  i;
//     // this function count the push from a to b
//     i = 1;
//     if (stack->data > n)
//         return (1);
//     while (stack && stack->data < n)
//     {
//         stack = stack->next;
//         ++i;
//     }
//     return (i);
// }

int *ft_count_sort_indexes(push *stack, int n)
{
    int  *i;
    // this funtion dont count the push time
    // index 0 for indexes befor the n
    // index 1 for indexes after the n
    //return 0 if the number in place to swap to top or push
    i = malloc(sizeof(int) * 2);
    if (!i)
        return (NULL);
    while (stack && stack->data != n)
    {
        i[0] += 1;
        stack = stack->next;
    }
    if (stack->data == n)
        stack = stack->next;
    while (stack && stack->data != n)
    {
        i[1] += 1;
        stack = stack->next;
    }
    return (i);
}

size_t  *put_number_in_b(push *stack, int n)
{
    size_t  *index;
    size_t  len;

    len = ft_lstsize(stack);
    index = malloc(sizeof(size_t) * 2);
    if (!index)
        return (NULL);
    while (stack && stack->data < n)
    {
        index[0] += 1;
        stack = stack->next;
    }
    stack[0] -= len;
    return (index);
}
