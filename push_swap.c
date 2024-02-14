/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:58:13 by achakour          #+#    #+#             */
/*   Updated: 2024/02/14 18:40:40 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **ar)
{
    push    *stack_a;
    push    *stack_b;
    int     stack_len;

    if (!ft_check_dobles_limits(ac, ar) || !ft_is_all_digit(ac, ar) || ac == 1)
        ft_perror();
    stack_b = NULL;
    stack_a = get_args(ac, ar);
    stack_len = ft_lstsize(stack_a);
    if (ft_is_sorted(stack_a))
        return (0);
    else if (is_descending(stack_a))
        //rotate the stack
    else if (stack_len == 3)
        sort_small_stack(&stack_a, &stack_b);
    else if (stack_len == 2)
        ra_rb_rr(stack_a, "ra");
    else
        
    return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
 