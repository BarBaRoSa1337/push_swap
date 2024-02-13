/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:14 by achakour          #+#    #+#             */
/*   Updated: 2024/02/12 19:03:44 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra_rrb_rrr(push **stack, push **last,char *flag)
{
    push    *head;
    push    *tmp;

    head = *stack;
    while (head->next->next)
        head = head->next;
   tmp = head;
   *last = tmp;
   head->next->next = *stack;
   *stack = tmp->next;
   tmp->next = NULL;
}

void    ra_rb_rr(push **stack, push **last,char *flag)
{
    push    *head;
    push    *tmp;

    head = *stack;
    tmp = head->next;
    while (head->next)
    {
        head = head->next;
    }
    head->next = *stack;
    *last = head->next;
    *stack = tmp;
    head->next->next = NULL;
}

void    pa_pb(push **stack_a, push **stack_b, push **last,char *flag)
{
    int     tmp;//thid function dont handle lstsize == 1//
    push    *head;

    if (flag[1] == 'a')
    {
        head = *stack_a;
        while (head->next->next)
            head = head->next;
        *last = head;
        tmp = head->next->data;
        ft_lstadd_back(stack_b, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    else if (flag[1] == 'b')
    {
        head = *stack_b;
        while (head->next->next)
            head = head->next;
        *last = head;
        tmp = head->next->data;
        ft_lstadd_back(stack_a, ft_lstnew(tmp));
        ft_lstclear(&head->next);
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

