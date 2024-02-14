#include "push_swap.h"

// int is_sorted(push *stack)
// {
//     int lst_size;

//     lst_size = ft_lstsize(stack);
//     while(lst_size--)
//     {
//         if (stack->data < stack->next->data)
//             stack = stack->next
//         else
//             return (0);
//     }
//     return (1);
// }

int    *ft_find_sequence(int *arr, int *lis, int max, int *len)
{
    int *seq;
    int tmp;
    int i;

    i = 0;
    tmp = *len;
    seq = malloc(sizeof(int) * max);
    if (!seq)
        return (NULL);
    while (tmp)
    {
        if (lis[tmp - 1] == max)
        {
            seq[i] = arr[tmp - 1];
            max--;
            ++i;
        }
        tmp--;
    }
    *len = i;
    free (lis);
    free(arr);
    return (seq);
}

int ft_max(int *arr, int len)
{
    int tmp;
    int i;

    i = 0;
    tmp = arr[i];
    while (i < len)
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

int    *ft_lis(push *lst, int *len)
{
    int *arr;
    int *lis;
    int tmp;
    int  i;
    int  j;

    i = 0;
    tmp = *len;
    lis = malloc(sizeof(int) * tmp);
    if (!lis)
        return (NULL);
    while (i < tmp)
        lis[i++] = 1;
    arr = ft_fill_arr(lst);
    i = 1;
    while (i < tmp)
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
    return (ft_find_sequence(arr, lis, ft_max(lis, tmp), len));
}
