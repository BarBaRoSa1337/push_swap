/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lsi_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:43 by achakour          #+#    #+#             */
/*   Updated: 2024/03/18 22:01:25 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_find_sequence(int *arr, int *lis, int max, int *len)
{
	int	*seq;
	int	tmp;
	int	i;

	i = 0;
	tmp = *len;
	seq = (int *)malloc(sizeof(int) * max);
	if (!seq)
	{ 
		return (NULL);
	}
	while (tmp)
	{
		if (lis[tmp - 1] == max)
		{
			seq[i] = arr[tmp - 1];
			max--;
			++i;
		}
		tmp--;
	}
	*len = i;
	free(lis);
	free(arr);
	return (seq);
}

int	find_max(int *arr, int len)
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

int	*ft_fill_arr(t_push *lst)
{
	t_push	*head;
	int		*arr;
	size_t	i;

	i = 0;
	if (!lst)
	{
		return (NULL);
	}
	head = lst;
	arr = (int *)malloc(sizeof(int) * ft_lstsize(lst));
	if (!arr)
	{
		return (NULL);
	}
	while (head)
	{
		arr[i] = head->data;
		head = head->next;
		++i;
	}
	return (arr);
}

void	set_arr(int *lis, int len)
{
	int	i;

	i = 0;
	while (i < len)
		lis[i++] = 1;
}

int	*ft_lis(t_push *lst, int *len)
{
	int	*arr;
	int	*lis;
	int	tmp;
	int	i;
	int	j;

	tmp = *len;
	lis = malloc(sizeof(int) * tmp);
	if (!lis)
		return (NULL);
	set_arr(lis, tmp);
	arr = ft_fill_arr(lst);
	i = 1;
	while (i < tmp)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 >= lis[i])
				lis[i] = lis[j] + 1;
			++j;
		}
		++i;
	}
	return (ft_find_sequence(arr, lis, find_max(lis, tmp), len));
}
