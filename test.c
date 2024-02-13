#include "push_swap.h"

// void    filter_lst(push **stack_a, push **stack_b, int *lis)
// {
//     int     stack_len;
//     push    *last;
//     push    *tmp;

//     last = *stack_a;
//     while (last->next->next)
//     {
//         last = last->next->next;
//         tmp = last->next;
//     }
//     stack_len = ft_lstsize(*stack_a);
//     while (stack_len--)
//     {
//         if (is_not_lis(lis, last->data))
//             pa_pb(stack_a, stack_b, "pa");
//         ra_rb_rr(stack_a, "ra");
//     }
// }

// rra (reverse rotate a): Shift down all elements of stack a by 1.
//  The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
//  The last element becomes the first one.
// rrr : rra and rrb at the same time.

int    *ft_find_sequence(int *arr, int *lis, int max, int len);

int ft_max(int *arr)
{
    int tmp;
    int i;

    i = 0;
    tmp = arr[i];
    while (arr[i])
    {
        if (arr[i] > tmp)
            tmp = arr[i];
        ++i;
    }
    return (tmp);
}

int    *ft_fill_arr(push *lst)
{
    size_t  i;
    int    *arr;

    arr = malloc(sizeof(int) * ft_lstsize(lst));
    if (!arr)
        return (NULL);
    i = 0;
    while (lst)
    {
        arr[i] = lst->data;
        lst = lst->next;
        ++i;
    }
    return (arr);
}

int is_valid(int *arr, int n, int len)
{
    int i =  0;
    while (i < len)
    {
        if (arr[i] == n)
            return (0);
        ++i;
    }
    return (1);
}

int    *ft_lis(push *lst, int len)
{
    int *arr;
    int *lis;
    int  i;
    int  j;

    i = 0;
    lis = malloc(sizeof(int) * len);
    if (!lis)
        return (NULL);
    while (i < len)
        lis[i++] = 1;
    arr = ft_fill_arr(lst);
    i = 1;
    while (i < len)
    {
        j = 0;
        while (j < i)
        {
            if (arr[j] < arr[i] && lis[j] + 1 >= lis[i])
                lis[i] = lis[j] + 1;
            ++j;
        }
        ++i;
    }
    return (ft_find_sequence(arr, lis, ft_max(lis), len));
}

#include <stdio.h>

int    *ft_find_sequence(int *arr, int *lis, int max, int len)
{
    int *seq;
    int i;

    i = 0;
    seq = malloc(sizeof(int) * max);
    if (!seq)
        return (NULL);
    while (len)
    {
        if (lis[len - 1] == max)
        {
            seq[i] = arr[len - 1];
            // printf ("%d\n", seq[i]);
            max--;
            ++i;
        }
        len--;
    }
    free (lis);
    free(arr);
    return (seq);
}

// push    *find_last_node(push *stack)
// {
//     while (stack->next)
//         stack = stack->next;
//     return(stack);
// }

// void    filter_lst(push **stack_a, push **stack_b)
// {
//     int     stack_len;
//     push    *last;
//     int     *lis;

//     lis = ft_lis(*stack_a);
//     stack_len = ft_lstsize(*stack_a);
//     last = find_last_node(*stack_a);
//     while (stack_len--)
//     {
//         if (is_lis(lis, last->data))
//         {
//             pa_pb(&stack_a, &stack_b, "pa");      
//         }
//         ra_rb_rr(*stack_a, "ra");
//     }
// }

// void    rra_rrb_rrr(push **stack, push **last,char *flag)
// {
//     push    head;

//     head = *stack;
//     while (head->next->next)
//         head = head->next;
//     *last = head;
//     *stack = head->next;
//     head->next = NULL;
// }
// int main(void)
// {
//     push *n = ft_lstnew(2);
//     push    *n1 = ft_lstnew(3);
//     push        *n2 = ft_lstnew(5);
//     push            *n3 = ft_lstnew(4);
//     push                *n4 = ft_lstnew(8);
//     n->next = n1;
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     push *head = n;
//     push *last;
//     rra_rrb_rrr(&head, &head, "ra");
//     for (int i = 0;i < 5; i++)
//     {
//         printf ("%d\n", n->data);
//         n = n->next;
//     }
//     // ft_lstclear(&n);
// }
