/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:11:09 by achakour          #+#    #+#             */
/*   Updated: 2024/02/01 15:25:51 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    put_swap_type(char flag)
{
    if (flag == 'a')
        ft_printf("ra ");
    else if (flag == 'b')
        ft_printf("rb ");
    else if (flag == 'r')
        ft_printf("rr ");
    else if (flag == 'A')
        ft_printf("rra ");
    else if (flag == 'B')
        ft_printf("rrb ");
    else if (flag == 'R')
        ft_printf("rrr ");
}

void    ra_rb_rr_rra_rrb_rrr(push *stack, char flag)
{
    size_t  stack_len;
    int     *tmp;
    size_t  i;

    i = 0;
    stack_len = ft_lstsize(stack);
    tmp = (int *)malloc(sizeof(int) * stack_len);
    if (!tmp)
        return (NULL);
    while (i < stack_len)
    {
        tmp[i] = stack->data;
        stack = stack->next;
        ++i;
    }
    while (stack_len--)
    {
        stack->data = tmp[stack_len];
        stack = stack->next;
    }
    put_swap_type(flag);
    free (tmp);
}

push    *pa_pb(push *a, push *b, char flag)
{
    int     tmp;
    push    *head;

    if (flag == 'a')
    {
        tmp = b->data;
        head = b->next;
        ft_lstadd_front(&a, ft_lstnew(tmp));
        ft_lstdelone(b);
        ft_printf("pa ");
    }
    else if (flag == 'b')
    {
        tmp = a->data;
        head = a->next;
        ft_lstadd_front(&b, ft_lstnew(tmp));
        ft_lstdelone(a);
        ft_printf("pb ");
    }
    return (head);
}

void    sa_sb_ss(push *stack, char flag)
{
    int tmp;

    if (!stack || !stack->next)
        return ;
    tmp = stack->data;
    stack->next->data = tmp;
    stack->data = tmp;
    if (flag == 'a')
        ft_printf("sa ");
    else if(flag == 'b')
        ft_printf("sb ");
    else if (flag == 's')
        ft_printf("ss");
}