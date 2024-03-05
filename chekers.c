/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:16:50 by achakour          #+#    #+#             */
/*   Updated: 2024/03/05 10:01:44 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

// int ft_double_numbers(int *arr, int n, unsigned int len)
// {
//     size_t i;
//     int flag;

//     i = 0;
//     flag = 0;
//     while (i < len)
//     {
//         if (arr[i] == n && flag)
//             return (0);
//         else if (arr[i] == n)
//             ++flag;
//         ++i;
//     }
//     return (1);
// }

// int ft_is_all_digit(int ac, char **ar)
// {
//     size_t i;
//     size_t j;

//     i = 1;
//     while (i < ac)
//     {
//         j = 0;
//         while (ar[i][j])
//         {
//             if (!ft_isdigit(ar[i][j]))
//                 return (0);
//             ++j;
//         }
//         ++i;
//     }
//     return (1);
// }

// int ft_check_dobles_limits(int ac, char **ar)
// {
//     size_t  i;
//     size_t  *tmp;

//     if (!tmp || ac == 1)
//         return (0);
//     tmp = (size_t *)malloc(sizeof(size_t) * ac - 1);
//     if (!tmp)
//         return (NULL);
//     i = 0;
//     while (i < ac)
//     {
//         tmp[i] = ft_atoi(ar[i + 1]);
//         if (tmp[i] > INT_MAX || tmp[i] < INT_MIN || !ft_doubles(tmp, tmp[i]))
//             return (free (tmp), 0);
//         ++i;
//     }
//     free (tmp);
//     return (1);
// }

size_t	ft_atoi(const char *str)
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


push    *get_args(int ac, char **ar)
{
    int     i;
    push    *lst;

    if (ac < 2)
        return (NULL);
    i = 1;
    lst = NULL;
    while (i < ac)
    {
       ft_lstadd_front(&lst, ft_lstnew(ft_atoi(ar[i])));
       ++i;
    }
    return (lst);
}