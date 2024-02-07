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

// char    *ft_find_sequence(int *arr, int lis, int max)
// {
//     int *seq;

//     seq = malloc(sizeof(int) * max);
//     if (!seq)
//         return (NULL);
//     while (max > -1)
//     {
//         seq[max - 1] = arr[lis[max]];
//         max--;
//     }
//     return (seq);
// }

// int    *ft_lis(push *lst, size_t len)
// {
//     int *arr;
//     int *lis;// dont forget to free lis and arr
//     int  i;
//     int  j;

//     i = 0;
//     lis = malloc(sizeof(int) * len);
//     if (!lis)
//         return (NULL);
//     while (i < len)
//         lis[i++] = 1;
//     arr = ft_fill_arr(lst);
//     i = 1;
//     while (i < len)
//     {
//         j = 0;
//         while (j < i)
//         {
//             if (arr[j] < arr[i] && lis[j] + 1 >= lis[i])
//                 lis[i] = lis[j++] + 1;
//             ++j;
//         }
//         ++i;
//     }
//     return (ft_find_sequence(arr, lis, ft_max(lis)), free(lis), free(arr), 0);
// }

// int main()
// {
//     push    *n1 = ft_lstnew(3)  ;
//     push        *n2 = ft_lstnew(5)  ;
//     push            *n3 = ft_lstnew(4)  ;
//     push                *n4 = ft_lstnew(8)   ;
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     push *head = n1;

//     // int arr[4] = {5, 1, -1, 0};
//     // printf ("max == %d\n", ft_max(arr));
//     int *n =  ft_lis((head), ft_lstsize(head));
//     printf ("%n")
//     // free (i);
//     // ft_lstclear(&head);
// }

int main(int ac, char **ar)
{
    // for (int i = 0;i < ac;i++)
    //     printf ("%s\n", ar[i]);
    // printf ("%d\n", ft_is_valid_num(ac,ar));
    printf ("%s\n", NULL);
}