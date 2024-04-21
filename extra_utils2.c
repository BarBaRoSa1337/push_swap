/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:32:03 by achakour          #+#    #+#             */
/*   Updated: 2024/04/21 14:56:03 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_perror(t_push **lst)
{
	ft_lstclear(lst);
	ft_putchar("Error");
	exit(1);
}

int	is_descending(t_push *stack)
{
	t_push	*head;
	int		len;

	head = stack;
	len = ft_lstsize(stack) - 1;
	while (head && head->next && head->data > head->next->data)
	{
		head = head->next;
		--len;
	}
	if (len == 0)
		return (1);
	return (0);
}

int	find_max_small(int *arr, int len)
{
	int	tmp;
	int	i;

	if (len < 1)
	{
		return (0);
	}
	i = 0;
	tmp = arr[i++];
	while (i < len)
	{
		if (arr[i] > tmp)
		{
			tmp = arr[i];
		}
		++i;
	}
	free (arr);
	return (tmp);
}

char	*ft_strdup(char *str)
{
	char	*p;
	int		len;

	len = ft_strlen(str);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(p, str, len + 1);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		buffer_size;
	char	*buffer;
	int		s1len;
	int		s2len;

	if (!s1 && s2)
	{
		return (ft_strdup(s2));
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	buffer_size = s1len + s2len + 1;
	buffer = (char *)malloc(buffer_size);
	if (!buffer)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, s1, buffer_size);
	ft_strlcpy(buffer + s1len, s2, buffer_size);
	free(s1);
	return (buffer);
}
