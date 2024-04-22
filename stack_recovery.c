/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_recovery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:35:28 by achakour          #+#    #+#             */
/*   Updated: 2024/04/22 10:48:12 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    **get_chars(int ac, char **ar)
{
    char    **buff;
    char    *tmp;
    int     i;

	if (ac == 1)
		return (NULL);
    i = 1;
	tmp = NULL;
    while (i < ac)
    {
		if (!ar[i][0] || is_all_spaces(ar[i]))
			return (free(tmp), NULL);
        tmp = ft_strjoin(tmp, ar[i]);
		tmp = ft_strjoin(tmp, " ");
        ++i;
    }
    buff = ft_split(tmp, ' ');
    return (free (tmp), buff);
}

void	select_move3(t_push **stack_a, t_push **stack_b, int *pos)
{
	if (pos[1] == 1)
	{
		while (pos[0] > 0 && pos[0]--)
			rra_rrb_rrr(stack_b, "rrb");
	}
	else if (pos[1] == -1)
	{
		while (pos[0] > 0 && pos[0]--)
			ra_rb_rr(stack_b, "rb");
	}
	if (pos[3] == 1)
	{
		while (pos[2] > 0 && pos[2]--)
			rra_rrb_rrr(stack_a, "rra");
	}
	else if (pos[3] == -1)
	{
		while (pos[2] > 0 && pos[2]--)
		{
			ra_rb_rr(stack_a, "ra");
		}
	}
	pa_pb(stack_a, stack_b, "pa");
}

void	select_move2(t_push **stack_a, t_push **stack_b, int *pos)
{
	while (pos[0] > 0 && pos[2] > 0 && pos[0]-- && pos[2]--)
	{
		rr_rrr(stack_a, stack_b, "rr");
	}
	while (pos[0] > 0 && pos[0]--)
	{
		ra_rb_rr(stack_b, "rb");
	}
	while (pos[2] > 0 && pos[2]--)
	{
		ra_rb_rr(stack_a, "ra");
	}
	pa_pb(stack_a, stack_b, "pa");
}

void	select_move1(t_push **stack_a, t_push **stack_b, int *pos)
{
	if (pos[1] == 1 && pos[3] == 1)
	{
		while (pos[0] > 0 && pos[2] > 0 && pos[0]-- && pos[2]--)
		{
			rr_rrr(stack_a, stack_b, "rrr");
		}
		while (pos[0] > 0 && pos[0]--)
		{
			rra_rrb_rrr(stack_b, "rrb");
		}
		while (pos[2] > 0 && pos[2]--)
		{
			rra_rrb_rrr(stack_a, "rra");
		}
		pa_pb(stack_a, stack_b, "pa");
	}
	else if (pos[1] == -1 && pos[3] == -1)
	{
		select_move2(stack_a, stack_b, pos);
	}
	else
	{
		select_move3(stack_a, stack_b, pos);
	}
}

void	stack_recovery(t_push **stack_a, t_push **stack_b, int a_len, int b_len)
{
	t_push	*head;
	int		index;
	int		*pos;

	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	head = *stack_b;
	index = select_cheapest(*stack_a, *stack_b, b_len, a_len);
	while (head->next && index--)
		head = head->next;
	pos = count_push_price(*stack_a, *stack_b, head->data, a_len);
	select_move1(stack_a, stack_b, pos);
	free(pos);
}
