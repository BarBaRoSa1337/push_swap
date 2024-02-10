/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_push_price.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:14:47 by achakour          #+#    #+#             */
/*   Updated: 2024/02/08 12:49:18 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
