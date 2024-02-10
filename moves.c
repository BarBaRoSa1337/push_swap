/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:14 by achakour          #+#    #+#             */
/*   Updated: 2024/02/09 04:14:55 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra_rrb_rrr(push *stack, size_t stack_len, char *flag)
{
    push    *p;
    int     *tmp;
    size_t  i;

    i = 0;
    tmp = (int *)malloc(sizeof(int) * stack_len);
    if (!tmp)
        return ;
    p = stack;
    while (i < stack_len)
    {
        tmp[i++] = stack->data;
        stack = stack->next;
    }
    p->data = tmp[i - 1];
    p = p->next;
    i = 0;
    while (i < stack_len - 1)
    {
        p->data = tmp[i++];
        p = p->next;
    }
    printf ("%s \n", flag);
    free (tmp);
}

// void    ra_rb_rr(push *stack, char *flag)
// {
//     size_t  stack_len;
//     push    *p;
//     int     *tmp;
//     size_t  i;

//     i = 0;
//     stack_len = ft_lstsize(stack);
//     tmp = (int *)malloc(sizeof(int) * stack_len);
//     if (!tmp)
//         return ;
//     p = stack;
//     while (i < stack_len)
//     {
//         tmp[i++] = stack->data;
//         stack = stack->next;
//     }
//     i = 1;
//     while (i < stack_len)
//     {
//         p->data = tmp[i++];
//         p = p->next;
//     }
//     p->data = tmp[0];
//     printf ("%s \n", flag);
//     free (tmp);
// }

void    pa_pb(push *stack_a, push *stack_b, char *flag)
{
    // not tested yet!!
    //needs double pointers because it updates the pointer if there 
    // the list still empty
    int     tmp;

    if (flag[1] == 'a')
    {
        while (stack_a)
            stack_a = stack_a->next;
        tmp = stack_a->data;
        ft_lstadd_back(b, ft_lstnew(tmp));
        ft_lstdelone(stack_a);
    }
    else if (flag[1] == 'b')
    {
        while (stack_a)
            stack_a = stack_a->next;
        tmp = stack_a->data;
        ft_lstadd_back(a, ft_lstnew(tmp));
        ft_lstdelone(stack_b);
    }
    printf ("%s \n", flag);
}

void    sa_sb_ss(push *stack, char *flag)
{
    int tmp;

    if (!stack->next)
        return ;
    while (stack->next->next)
        stack = stack->next;
    if (!stack->next)
        return ;
    tmp = stack->next->data;
    stack->next->data = stack->data;
    stack->data = tmp;
    printf ("%s \n", flag);
}

