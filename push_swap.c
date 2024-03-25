/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/03/25 15:03:01 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_push *stack)// too many functions
{
	t_push	*head;
	int		len;

	head = stack;
	len = ft_lstsize(stack) - 1;
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
		stack_recovery(stack_a, stack_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		--len;
	}
}

void	push_swap(t_push **stack_a, t_push **stack_b)
{
	int		stack_len;
	t_push	*head;
	int		*lis;
	int		tmp;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	head = *stack_a;
	stack_len = ft_lstsize(head);
	tmp = stack_len;
	(void)tmp;
	lis = ft_lis(head, &stack_len);
	while (tmp && lis)
	{
		head = *stack_a;
		if (!is_lis(lis, stack_len, head->data))
		{
			pa_pb(stack_a, stack_b, "pb");
		}
		rra_rrb_rrr(stack_a, "rra");
		--tmp;
	}
	stack_len = ft_lstsize(*stack_b);
	while (stack_len--)
		stack_recovery(stack_a, stack_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
	free(lis);
}

t_push    *get_args(char **ar)
{
    int     i;
    t_push    *lst;

    i = 1;
    lst = NULL;
    while (ar[i])
    {
       ft_lstadd_back(&lst, ft_lstnew(ft_atoi(ar[i])));
       ++i;
    }
    return (lst);
}

int	main(int ac, char **ar)
{
	int		stack_len;
	t_push	*stack_b;
	t_push	*stack_a;
	ssize_t	*weight;

	stack_a = get_args(ar);
	if (ac == 1 || is_sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
	stack_len = ft_lstsize(stack_a);
	if (stack_len == 3)
		sort_three(&stack_a);
	else if (stack_len == 5)
		sort_five(&stack_a, &stack_b);
	else
	{
		weight = lst_weight(stack_a, stack_len);
		if (weight[0] > weight[1])
			rotate_half_stack(&stack_a, stack_len, "ra");
		push_swap(&stack_a, &stack_b);
		fix_lst(&stack_a, ft_lstsize(stack_a));
		free(weight);
	}
	return (ft_lstclear(&stack_a), 0);
}
