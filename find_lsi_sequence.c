/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lsi_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:43 by achakour          #+#    #+#             */
/*   Updated: 2024/02/15 18:07:19 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *ft_find_sequence(int *arr, int *lis, int max, int *len)
{
    int *seq;
    int tmp;
    int i;

    i = 0;
    tmp = *len;
    seq = malloc(sizeof(int) * max);
    if (!seq)
        return (NULL);
    while (tmp)
    {
        if (lis[tmp - 1] == max)
        {
            seq[i] = arr[tmp - 1];
            max--;
            ++i;
        }
        tmp--;
    }
    *len = i;
    free (lis);
    free(arr);
    return (seq);
}

int find_max(int *arr, int len)
{
    int tmp;
    int i;

    i = 0;
    tmp = arr[i];
    while (i < len)
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

int locate_fill_buffer(int **buff, int len)
{
    int i;

    i = 0;
    *buff = malloc(sizeof(int) * len);
    if (!buff)
        return (0);
    while (i < len)
    {
        *buff[i] = 1;
        ++i;
    }
}

int    *ft_lis(push *lst, int *len)
{
    int *arr;
    int *lis;
    int tmp;
    int  i;
    int  j;

    i = 0;
    tmp = *len;
    if (!locate_fill_buffer(&lis, *len))
        return (0);
    arr = ft_fill_arr(lst);
    i = 1;
    while (i < tmp)
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
    return (ft_find_sequence(arr, lis, find_max(lis, tmp), len));
}
