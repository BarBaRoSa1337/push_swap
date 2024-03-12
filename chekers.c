/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:16:50 by achakour          #+#    #+#             */
/*   Updated: 2024/03/11 09:35:01 by achakour         ###   ########.fr       */
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

// int	is_valid_args(char *buff)
// {
// 	char	**args;
// 	int	i;

// 	i = 0;
// 	args = ft_split(buff, ' ');
// 	while (args[i])
// 	{
// 		if (!ft_isdigit(args[i]) || is_doubled(args[i], args, i) || is_in_range(ft_atoi(args[i])))
// 			return (NULL);
// 		++i;
// 	}
// 	i = 0;
// 	while (args[i])
// 	{
// 		ft_lstadd_front()
// 	}
	
// 	return (args);
// }

push    *get_args(int ac, char **ar)
{
    push    *lst;
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

// char    *get_args(int ac, char **ar)
// {
//     char    *buff;
//     int     len;
//     int     z;
//     int     j;
//     int     i;

//     i = 1;
//     len = 0;
//     while (i < ac)
//         len += ft_strlen(ar[i++]);
//     buff = malloc(sizeof(char) * len + ac);
//     if (!buff)
//         return (NULL);
//     i = 1;
//     z = 0;
//     while (i < ac)
//     {
//         j = 0;
//         while (ar[i][j])
//             buff[z++] = ar[i][j++];
//         if (i < ac)
//             buff[z++] = ' ';
//         ++i;
//     }
//     return (buff);
// }