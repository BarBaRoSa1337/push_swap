/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:16:50 by achakour          #+#    #+#             */
/*   Updated: 2024/04/21 15:06:27 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	ft_atoi(const char *str)
{
	ssize_t	sign;
	ssize_t	num;
	int	i;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && str[i] == ' ')
		++i;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num * sign);
}

int	is_valid_args(char **ar)
{
	int	i;
	int	j;

	i = -1;
	while (ar[++i])
	{
		j = -1;
        while (ar[i][++j])
        {
			if (ar[i][j + 1] && (ar[i][j] == '-' || ar[i][j] == '+') && (ar[i][j
					+ 1] == '+' || ar[i][j + 1] == '-'))
				return (0);
			else if (ar[i][j + 1] && ft_isdigit(ar[i][j]) && !ft_isdigit(ar[i][j
					+ 1]))
				return (0);
			else if (!ft_isdigit(ar[i][j]) && (ar[i][j] != '-'
					&& ar[i][j] != '+'))
				return (0);
		}
	}
	i = -1;
	while (ar[++i])
		free(ar[i]);
	free(ar);
	return (1);
}

int	check_doubles(char **ar)
{
	int	i;
	int	j;

	i = -1;
	while (ar[++i])
	{
		if (ft_atoi(ar[i]) > INT_MAX || ft_atoi(ar[i]) < INT_MIN)
			return (ft_freebuff(ar), 0);
	}
	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[j])
		{
			if ((i != j) && (ft_atoi(ar[i]) == ft_atoi(ar[j])))
				return (ft_freebuff(ar), 0);
			++j;
		}
		++i;
	}
	return (ft_freebuff(ar), 1);
}

t_push	*get_args(char **ar)
{
	t_push	*lst;
	int		i;

	if (!ar || !*ar)
		return (NULL);
	i = 0;
	lst = NULL;
	while (ar[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(ar[i])));
		++i;
	}
	i = -1;
	while (ar[++i])
		free (ar[i]);
	free(ar);
	return (lst);
}
