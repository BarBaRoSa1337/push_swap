/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:38 by achakour          #+#    #+#             */
/*   Updated: 2024/03/15 14:09:02 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_push **lst, t_push *new)// too many functions
{
	if (!new || lst == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *(lst);
	*lst = new;
}

void	ft_lstadd_back(t_push **lst, t_push *new)
{
	t_push	*head;

	if (!new || lst == NULL)
	{
		return ;
	}
	head = *lst;
	if (!head)
	{
		*lst = new;
		return ;
	}
	while (head->next)
	{
		head = head->next;
	}
	head->next = new;
}

void	ft_lstclear(t_push **lst)
{
	t_push	*next_node;

	if (lst == NULL || *lst == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		next_node = (*lst)->next;
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_push **lst)
{
	if (lst == NULL)
	{
		return ;
	}
	free(*lst);
	lst = NULL;
}

int	ft_lstsize(t_push *lst)
{
	t_push	*head;
	int		len;

	len = 0;
	if (!lst)
	{
		return (0);
	}
	head = lst;
	while (head != NULL)
	{
		head = head->next;
		++len;
	}
	return (len);
}

t_push	*ft_lstnew(int content)
{
	t_push	*node;

	node = (t_push *)malloc(sizeof(t_push));
	if (!node)
	{
		return (NULL);
	}
	node->data = content;
	node->next = NULL;
	return (node);
}

t_push	*find_last_node(t_push *stack)
{
	if (!stack)
	{
		return (NULL);
	}
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}
