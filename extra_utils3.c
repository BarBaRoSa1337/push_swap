/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:52:15 by achakour          #+#    #+#             */
/*   Updated: 2024/04/22 10:58:39 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_all_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] == ' ')
        ++i;
    if (!str[i])
        return (1);
    return (0);
}

void    ft_freebuff(char **buff)
{
    int i;

    i = 0;
    while (buff[i])
    {
        free(buff[i]);
        ++i;
    }
    free(buff);
}

void    select_sort(t_push **stack_a, t_push **stack_b, int stack_len)
{
    if (stack_len == 2)
        sa_sb(stack_a, "sa");
    else if (stack_len == 3)
        sort_three(stack_a);
    else if (stack_len == 5)
        sort_five(stack_a, stack_b);
}
