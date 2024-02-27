#include "push_swap.h"

int detect_target(push *stack, int n, int a_len)
{
    int *arr;
    int key;
    int i;
    int j;

    i = 1;
    arr = ft_fill_arr(stack);
    while (i < a_len)
    {
        j = i - 1;
        key = arr[i];
        while (j > -1 && arr[j] > arr[j + 1])
        {
            arr[j + 1] = arr[j];
            arr[j] = key;
            --j;
        }
        ++i;
    }
    while (arr[i--] > n)
    key = arr[i];
    return (free(arr), key);
}

int main(int ac, char **ar)
{
    push *n = ft_lstnew(2);
    push    *n1 = ft_lstnew(8);
    push        *n2 = ft_lstnew(1);
    push            *n3 = ft_lstnew(4);
    push                *n4 = ft_lstnew(3);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    push    *b = ft_lstnew(5);
    push    *b1 = ft_lstnew(6);
    push    *b2  = ft_lstnew(9);
    b->next = b1;
    b1->next = b2;

    int arr = detect_target(n, 11, ft_lstsize(n));
    printf("%d\n", arr);
    push *head = n;
    push *stack = b;
    // while (head)
    // {
    //     printf ("1  %d\n", head->data);
    //     head = head->next;
    // }
    // while (b)
    // {
    //     printf ("2  %d\n", b->data);
    //     b = b->next;
    // }
    ft_lstclear(&n);
    // ft_lstclear(&b);
    ft_lstclear(&stack);
}