/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/11 18:46:01 by achakour         ###   ########.fr       */
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

int ft_max(int *arr)
{
    int tmp;
    int i;

    i = 0;
    tmp = arr[i];
    while (arr[i])
    {
        if (arr[i] > tmp)
            tmp = arr[i];
        ++i;
    }
    return (tmp);
}

int    *ft_fill_arr(push *lst)
{
    size_t  i;
    int    *arr;

    arr = malloc(sizeof(int) * ft_lstsize(lst));
    if (!arr)
        return (NULL);
    i = 0;
    while (lst)
    {
        arr[i] = lst->data;
        lst = lst->next;
        ++i;
    }
    return (arr);
}

int    *ft_lis(push *lst, int len)
{
    int *arr;
    int *lis;
    int  i;
    int  j;

    i = 0;
    lis = malloc(sizeof(int) * len);
    if (!lis)
        return (NULL);
    while (i < len)
        lis[i++] = 1;
    arr = ft_fill_arr(lst);
    i = 1;
    while (i < len)
    {
        j = 0;
        while (j < i)
        {
            if (arr[j] < arr[i] && lis[j] + 1 >= lis[i])
                lis[i] = lis[j] + 1;
            ++j;
        }
        ++i;
    }
    return (ft_find_sequence(arr, lis, ft_max(lis), len));
}

int    *ft_find_sequence(int *arr, int *lis, int max, int len)
{
    int *seq;
    int i;

    i = 0;
    seq = malloc(sizeof(int) * max);
    if (!seq)
        return (NULL);
    while (len)
    {
        if (lis[len - 1] == max)
        {
            seq[i] = arr[len - 1];
            // printf ("%d\n", seq[i]);
            max--;
            ++i;
        }
        len--;
    }
    free (lis);
    free(arr);
    return (seq);
}

push    *find_last_node(push *stack)
{
    while (stack->next)
        stack = stack->next;
    return(stack);
}
