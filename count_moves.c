/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:42:21 by achakour          #+#    #+#             */
/*   Updated: 2024/02/01 15:32:54 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_count_index(push *stack, int n)
{
    size_t  index;

    index = 0;
    while (stack && stack->data != n)
    {
        ++index;
        stack = stack->next;
    }
    return (index);
}

int ft_is_sorted(push *stack)
{
    while (stack->next)
    {
        if (stack->data < stack->next->data)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int ft_count_moves(push *a, push *b)
{
    size_t  alen;
    size_t  blen;
    int     index;

    alen = ft_lstsize(a);
    blen = ft_lstsize(b);

    if (alen >= blen)
    {
        
    }
}