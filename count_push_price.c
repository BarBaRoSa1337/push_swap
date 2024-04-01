/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_push_price.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:25:51 by achakour          #+#    #+#             */
/*   Updated: 2024/03/31 15:01:12 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int detect_target(int *arr, int n, int a_len)
{
    int key;
    int i;
    int j;

    i = 1;
    while (i < a_len)
    {
        j = i - 1;
        key = arr[i];
        while (j > -1 && arr[j] > arr[j + 1])
        {
            arr[j + 1] = arr[j];
            arr[j] = key;
            --j;
        }
        ++i;
    }
    i = 0;
    while (i < a_len && arr[i] < n)
        ++i;
    if (i > 0)
        key = arr[i - 1];
    else
        key = arr[a_len - 1];        
    return (free(arr), key);
}

void find_cheapest_in_a(t_push *stack, int **cheap, int target, int a_len)
{
    t_push    *head;

    head = stack;
    (*cheap)[2] = 0;
    while (head && head->data != target)
    {
        (*cheap)[2] += 1;
        head = head->next;
    }
    if (head->data ==  target)
        (*cheap)[2] += 1;
    (*cheap)[3] = a_len - (*cheap)[2];
    if ((*cheap)[2] < (*cheap)[3])
    {
        (*cheap)[3] = -1;
    }
    else
    {
        (*cheap)[2] = (*cheap)[3];
        (*cheap)[3] = 1;
    }
}

int *count_push_price(t_push *stack_a, t_push *stack_b, int n, int target, int b_len)
{
    t_push    *head_b;
    int     *pos;

    pos = malloc(sizeof(int) * 4);
    if (!pos)
        return (NULL);
    pos[0] = 0;
    head_b = stack_b;
    while (head_b && head_b->data != n)
    {
        pos[0] += 1;
        head_b = head_b->next;
    }
    pos[1] = b_len - pos[0];
    if (pos[0] < pos[1])
    {
        pos[1] = -1;
    }
    else
    {
        pos[0] = pos[1];
        pos[1] = 1;
    }
    find_cheapest_in_a(stack_a, &pos, target, ft_lstsize(stack_a));
    return (pos);
}

int select_cheapest(t_push *stack_a, t_push *stack_b, int b_len, int a_len)
{
    t_push    *head;
    int     best[2];
    int     i;
    int     *tmp;

    i = 0;
    head = stack_b;
    while (i < b_len)
    {
        tmp = count_push_price(stack_a, stack_b, head->data, detect_target(ft_fill_arr(stack_a), head->data, a_len), b_len);
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
        free(tmp);
        head = head->next;
        ++i;
    }
    return(best[1]);
}
