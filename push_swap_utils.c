/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:56:42 by achakour          #+#    #+#             */
/*   Updated: 2024/02/01 15:28:58 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_double_numbers(int *arr, int n, unsigned int len)
{
    size_t i;
    int flag;

    i = 0;
    flag = 0;
    while (i < len)
    {
        if (arr[i] == n && flag)
            return (0);
        else if (arr[i] == n)
            ++flag;
        ++i;
    }
    return (1);
}

int ft_is_all_digit(int ac, char **ar)
{
    size_t i;
    size_t j;

    i = 1;
    if (ac == 1)
        return (0);
    while (i < ac)
    {
        j = 0;
        while (ar[i][j])
        {
            if (!ft_isdigit(ar[i][j]))
                return (0);
            ++j;
        }
        ++i;
    }
    return (1);
}

int ft_check_dobles_limits(int ac, char **ar)
{
    size_t i;
    int *tmp;

    tmp = (int *)malloc(sizeof(int) * ac - 1);
    if (!tmp || ac == 1)
        return (0);
    i = 0;
    while (i < ac)
    {
        tmp[i] = ft_atoi(ar[i + 1]);
        if (tmp[i] > INT_MAX || tmp[i] < INT_MIN || ft_doubles(tmp, tmp[i]) == 0)
            return (0);
        ++i;
    }
    return (1);
}

push *get_args(int ac, char **ar)
{
    int i;
    int *tmp;
    push *lst;
    push *node;

    tmp = (int *)malloc(sizeof(int) * ac - 1);
    if (!tmp || ac <= 1)
        return (NULL);
    i = 0;
    while (i < ac - 1)
        tmp[i++] = ft_atoi(ar[i + 1]);
    i = 0;
    lst = ft_lstnew(tmp[i++]);
    node = lst;
    while (i < ac - 1)
    {
        node->next = ft_lstnew(tmp[i]);
        node = node->next;
        ++i;
    }
    free(tmp);
    return (lst);
}

int main(int ac, char **ar)
{
    push *lst =  get_args(ac, ar);
    while (lst != NULL)
    {
        printf("%d\n", lst->data);
        lst = lst->next;
    }
    printf("%d", ft_lstsize(lst));
    return (0);
}