/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:07:51 by achakour          #+#    #+#             */
/*   Updated: 2024/02/06 13:26:48 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    *ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] != s2[i])
            return (0);
        ++i;
    }
    return (1);
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

// void    ft_find_sorted_numbers(push *lst, size_t len)
// {
//     int arr[len];
//     int length[len];
//     int  i;
//     int  j;

//     i = 0;
//     while (i < len)
//         length[i++] = 1;
//     arr = ft_fill_arr(lst);
//     i = 1;
//     while (i < len)
//     {
//         j = 0;
//         while (j < i)
//         {
//             if (arr[j] < arr[i] && length[j] + 1 >= length[i])
//             {
//                 length[i] = length[j] + 1;
//                 printf ("%d\n", length[j]);
//                 lic[i - 1] = j;
//             }
//             ++j;
//         }
//         ++i;
//     }
// }

// int *ft_lst_weigth(push *stack, size_t len)
// {
//     size_t  i;
//     int  *weight;

//     weight = malloc (sizeof(int) * 2);
//     if (!weight)
//         return (NULL);
//     i = 0;
//     while (i < len / 2)
//     {
//         weight[0] += stack->data;
//         stack = stack->next;
//         ++i;
//     }
//     if (((len / 2) % 2) != 0 && len != 2)
//         stack = stack->next;
//     while (stack)
//     {
//         weight[1] += stack->data;
//         stack = stack->next;
//     }
//     return (weight);
// }
