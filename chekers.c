/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:16:50 by achakour          #+#    #+#             */
/*   Updated: 2024/03/26 13:47:21 by achakour         ###   ########.fr       */
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

ssize_t	ft_atoi(const char *str)
{
	ssize_t	sign;
	size_t	num;
	int		i;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
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

// char	*get_args1(int ac, char **ar)
// {
// 	char	*buff;
// 	int		len;
// 	int		z;
// 	int		j;
// 	int		i;

// 	i = 1;
// 	len = 0;
// 	while (i < ac)
// 		len += ft_strlen(ar[i++]);
// 	buff = (char *)malloc(sizeof(char) * len + ac);
// 	if (!buff)
// 		return (NULL);
// 	i = 1;
// 	z = 0;
// 	while (i < ac)
// 	{
// 		j = 0;
// 		while (ar[i][j])
// 			buff[z++] = ar[i][j++];
// 		if (i < ac)
// 			buff[z++] = ' ';
// 		++i;
// 	}
// 	return (buff);
// }

// t_push    *get_args(char **ar)
// {
//     int     i;
//     t_push    *lst;

//     i = 1;
//     lst = NULL;
//     while (ar[i])
//     {
//        ft_lstadd_back(&lst, ft_lstnew(ft_atoi(ar[i])));
//        ++i;
//     }
//     return (lst);
// }
