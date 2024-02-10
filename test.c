#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
//  The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
//  The last element becomes the first one.
// rrr : rra and rrb at the same time.

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
int is_valid(int *arr, int n, int index)
{
    int i =  0;
    while (i < index)
    {
        if (arr[i] == n)
            return (0);
        ++i;
    }
    return (1);
}
int    *ft_find_sequence(int *arr, int *lis, int max)
{
    int *seq;
    int i = 0;
    
    seq = malloc(sizeof(int) * max);
    memset(seq, 0, max);
    if (!seq)
        return (NULL);
    while (max)
    {
       if (is_valid(seq, arr[lis[max]], i))
       {
            seq[i] = arr[lis[max]];
            ++i;
       }
       --max;
    }
    free (lis);
    return (seq);
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
    return (ft_find_sequence(arr, lis, ft_max(lis)));
}

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

#include <stdio.h>

int main(void)
{
    push *n = ft_lstnew(2);
    push    *n1 = ft_lstnew(3);
    push        *n2 = ft_lstnew(5);
    push            *n3 = ft_lstnew(4);
    push                *n4 = ft_lstnew(8);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    push *head = n;

    int max;
    int *arr = ft_lis(head, ft_lstsize(head));
    for (int i = 0; i < max; i++)
        printf("%d\n", arr[i]);
    // // sa_sb_ss(head, "sa");
    // while (n)
    // {
    //     printf ("%d\n", n->data);
    //     n = n->next;
    // }
    free (arr);
}
