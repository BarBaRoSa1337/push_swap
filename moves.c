/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:14 by achakour          #+#    #+#             */
/*   Updated: 2024/02/10 18:23:54 by achakour         ###   ########.fr       */
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

void    ra_rb_rr(push *stack, char *flag)
{
    int     stack_len;
    int     *tmp;
    push    *p;
    int     i;

    i = 0;
    stack_len = ft_lstsize(stack);
    tmp = (int *)malloc(sizeof(int) * stack_len);
    if (!tmp)
        return ;
    p = stack;
    while (i < stack_len)
    {
        tmp[i++] = stack->data;
        stack = stack->next;
    }
    i = 1;
    while (i < stack_len)
    {
        p->data = tmp[i++];
        p = p->next;
    }
    p->data = tmp[0];
    printf ("%s \n", flag);
    free (tmp);
}

void    pa_pb(push **stack_a, push **stack_b, char *flag)
{
    int     tmp;
    push    *head;

    if (flag[1] == 'a')
    {
        head = *stack_a;
        while (head->next)
            head = head->next;
        tmp = head->data;
        ft_lstadd_back(&stack_b, ft_lstnew(tmp));
        ft_lstdelone(head);
    }
    else if (flag[1] == 'b')
    {
        head = *stack_b;
        while (head->next)
            head = head->next;
        tmp = head->data;
        ft_lstadd_back(&stack_a, ft_lstnew(tmp));
        ft_lstdelone(head);
    }
    printf ("%s \n", flag);//aba!
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

