/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:52:15 by achakour          #+#    #+#             */
/*   Updated: 2024/04/20 14:56:10 by achakour         ###   ########.fr       */
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