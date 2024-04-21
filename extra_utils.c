/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:31:57 by achakour          #+#    #+#             */
/*   Updated: 2024/04/21 15:14:35 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_lstdelone(t_push **lst)
{
	t_push	*head;

	if (lst == NULL)
	{
		return ;
	}
	head = *lst;
	free(head);
	head = NULL;
}

int	push_node(t_push **stack_a, t_push **stack_b, int a_len, char *flag)
{
	t_push	*head;
	int		b_len;
	int		tmp;

	if (!*stack_b)
		return 0;
	b_len = ft_lstsize(*stack_b);
	if (flag[1] == 'b' && a_len == 1)
	{
		head = *stack_a;
		tmp = head->data;
		ft_lstadd_front(stack_b, ft_lstnew(tmp));
		ft_lstdelone(&head);
		ft_putchar(flag);
		return (1);
	}
	else if (flag[1] == 'a' && b_len == 1)
	{
		head = *stack_b;
		tmp = head->data;
		ft_lstadd_front(stack_a, ft_lstnew(tmp));
		ft_lstdelone(&head);
		ft_putchar(flag);
		return (1);
	}
	return (0);
}

int	is_sorted(t_push *stack)
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

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (*(src + i) != '\0' && --dstsize)
		{
			*(dst + i) = *(src + i);
			++i;
		}
		*(dst + i) = '\0';
	}
	return (srclen);
}
