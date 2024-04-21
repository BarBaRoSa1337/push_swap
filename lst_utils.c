/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:38 by achakour          #+#    #+#             */
/*   Updated: 2024/04/21 15:19:26 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_push **lst, t_push *new)
{
	if (!new)
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
