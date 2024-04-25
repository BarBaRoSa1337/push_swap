/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:30:58 by achakour          #+#    #+#             */
/*   Updated: 2024/04/25 16:04:14 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    process_line(char *line)
{
        
}

int main(int ac, char **ar)
{
    char    *line;
    t_push  *stack_a;
    t_push  *stack_b;

    stack_b = NULL;
    stack_a = get_args(get_chars(ac, ar));
    if (ac > 1 && (!stack_a || !is_valid_args(get_chars(ac, ar))
            || !check_doubles(get_chars(ac, ar))))
    {
        ft_perror(&stack_a);
    }
    while (1)
    {
        line = get_next_line(0);
        if (!line)
            break ;
        process_line(line);
    }
    ft_lstclear(&stack_a);
    if (stack_b)
        ft_perror(&stack_b);
    return (0);
}
