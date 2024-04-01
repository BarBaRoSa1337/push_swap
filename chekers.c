/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:16:50 by achakour          #+#    #+#             */
/*   Updated: 2024/04/01 23:48:12 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

ssize_t	ft_atoi(const char *str)
{
	size_t	num;
	ssize_t	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num * sign);
}

int	is_valid_args(int ac, char **ar)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		return (1);
	while (ar[i])
	{
		j = 0;
		while (ar[i][j])
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
			++j;
		}
		++i;
	}
	return (1);
}

int check_doubles(int ac, char **ar)
{
    int     i;
    int     j;

    i = 1;
    while (i < ac)
    {
        j = 1;
        if (ft_atoi(ar[i]) > INT_MAX || ft_atoi(ar[i]) < INT_MIN)
                return (0);
        while (j < ac)
        {
            if ((i != j) && (ft_atoi(ar[i]) == ft_atoi(ar[j])))
                return (0);
            ++j;
        }
        ++i;
    }
    return (1);
}

t_push    *get_args(int ac, char **ar)
{
    t_push    *lst;
    int     i;

    if (ac < 2)
        return (NULL);
    i = 1;
    lst = NULL;
    while (i < ac)
    {
       ft_lstadd_back(&lst, ft_lstnew(ft_atoi(ar[i])));
       ++i;
    }
    return (lst);
}
