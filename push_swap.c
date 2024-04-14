/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/04/14 11:46:27 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_push *stack)
{
    t_push *head;
    head = stack;
    while (head)
    {
        printf("||%d||\n", head->data);
        head = head->next;
    }
}

int is_sorted(t_push *stack)
{
    t_push *head = stack;
    int len = ft_lstsize(stack) - 1;
    
    while (head && head->next && head->data < head->next->data)
    {
        head = head->next;
        --len;
    }
    if (len == 0)
        return (1);
    return (0);
}

void	sort_three(t_push **stack_a)
{
	t_push	*head;
	int		*min;
	int		max;

	head = *stack_a;
	min = get_min(head);
	max = find_max(ft_fill_arr(head), ft_lstsize(*stack_a));
	if (head->data == max)
	{
		ra_rb_rr(stack_a, "ra");
	}
	else if (head->next->data == max)
	{
		rra_rrb_rrr(stack_a, "rra");
	}
	head = *stack_a;
	if (head->data > head->next->data)
	{
		sa_sb(stack_a, "sa");
	}
	free(min);
}

void	push_node_to_b(t_push **stack_a, t_push **stack_b, int min, int a_len)
{
	t_push	*head;
	int		pos[2];

	pos[0] = 0;
	head = *stack_a;
	while (head && head->data != min)
	{
		pos[0]++;
		head = head->next;
	}
	pos[1] = a_len - pos[0];
	if (pos[0] > pos[1])
	{
		while (pos[1] > 0 && pos[1]--)
		{
			rra_rrb_rrr(stack_a, "rra");
		}
	}
	else
	{
		while (pos[0] > 0 && pos[0]--)
			ra_rb_rr(stack_a, "ra");
	}
	pa_pb(stack_a, stack_b, "pb");
}

void	sort_five(t_push **stack_a, t_push **stack_b)
{
	t_push	*head;
	int		*min;
	int		len;

	if (!stack_a || !*stack_a)
		return ;
	head = *stack_a;
	*stack_b = NULL;
	len = ft_lstsize(head);
	while (len > 3)
	{
		min = get_min(head); 
		push_node_to_b(stack_a, stack_b, min[0], ft_lstsize(*stack_a));
		head = *stack_a;
		free(min);
		len--;
	}
	len = ft_lstsize(*stack_b);
	sort_three(stack_a);
	while (len)
	{
		stack_recovery(stack_a, stack_b);
		--len;
	}
}

void    push_swap(t_push **stack_a, t_push **stack_b)
{
    int     stack_len;
    t_push    *head;
    int     *lis;
    int     tmp;

    if (!stack_a || !*stack_a)
        return ;
    head = *stack_a;
    stack_len = ft_lstsize(head);
    tmp = stack_len;
    lis = ft_lis(head, &stack_len);
    while (tmp-- && lis && stack_len > 0)
    {
        head = *stack_a;
        if (!is_lis(lis, stack_len, head->data))
        {
            pa_pb (stack_a, stack_b, "pb");
        }
        rra_rrb_rrr(stack_a, "rra");
    }
    stack_len = ft_lstsize(*stack_b);
    while (stack_len--)
        stack_recovery(stack_a, stack_b);
    free (lis);
}

int is_descending(t_push *stack)
{
    t_push *head = stack;
    int len = ft_lstsize(stack) - 1;
    
    while (head && head->next && head->data > head->next->data)
    {
        head = head->next;
        --len;
    }
    if (len == 0)
        return (1);
    return (0);
}
void ft_perror(t_push **lst)
{
    ft_putchar("Error");
    ft_lstclear(lst);
    return ;
}

int main(int ac, char **ar)
{
    int         stack_len;
    t_push        *stack_b;
    t_push        *stack_a;

    stack_a = get_args(ac, ar);
    stack_len = ft_lstsize(stack_a);
    if (!check_doubles(ac ,ar) || !is_valid_args(ac ,ar))
        ft_perror(&stack_a);
    else if (ac == 1 || is_sorted(stack_a))
        return (ft_lstclear(&stack_a), 0);
    else if (stack_len == 2)
        sa_sb(&stack_a, "sa");
    else if (stack_len == 3)
        sort_three(&stack_a);
    else if (stack_len == 5)
        sort_five(&stack_a, &stack_b);
    else
    {
        if (is_descending(stack_a))
            rotate_half_stack(&stack_a, stack_len, "rra");
        push_swap(&stack_a, &stack_b);
        fix_lst(&stack_a, ft_lstsize(stack_a));
    }
    return (ft_lstclear(&stack_a), 0);
}

