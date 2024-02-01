/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:05 by achakour          #+#    #+#             */
/*   Updated: 2024/02/01 15:29:34 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct  push
{
    int data;
    struct push* next;
} push;

push	*ft_lstnew(int content);
int     ft_atoi(const char *str);
int	    ft_lstsize(push *lst);
int	    ft_printf(const char *format, ...);
void	ft_lstclear(push **lst);
void	ft_lstadd_front(push **lst, push *new);
void	ft_lstdelone(push *lst);
int	    ft_lstsize(push *lst);
push	*ft_lstnew(int content);

#endif