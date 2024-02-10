/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/10 18:13:59 by achakour         ###   ########.fr       */
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

int    *ft_fill_arr(push *lst)
{
    size_t  i;
    int    *arr = malloc(sizeof(int) * ft_lstsize(lst));
    i = 0;
    while (lst)
    {
        arr[i] = lst->data;
        lst = lst->next;
        ++i;
    }
    return (arr);
}

