/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lsi_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:43 by achakour          #+#    #+#             */
/*   Updated: 2024/03/26 15:01:07 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*ft_find_sequence(int *arr, int *lis, int max, int *len)
{
	int	*seq;
	int	tmp;
	int	i;

	i = 0;
	tmp = *len;
	if (max <= 0)
		return (NULL);
	seq = (int *)malloc(sizeof(int) * max);
	if (!seq)
		return (NULL);
	while (tmp > 0 && max > 0)
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
	free(arr);
	return (seq);
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

// void	set_arr(int **lis, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		*lis[i] = 1;
// 		++i;
// 	}
// }

int	*ft_lis(t_push *lst, int *len)
{
	int	*arr;
	int	*lis;
	int	tmp;
	int	i;
	int	j;

	tmp = *len;
	lis = malloc(sizeof(int) * tmp);
	i = 0;
	while (lis && i < tmp)
		lis[i++] = 1;
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
