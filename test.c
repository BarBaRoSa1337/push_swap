#include "push_swap.h"

int detect_target(push *stack, int n, int *arr, int a_len)
{
    int key;
    int i;
    int j;

    i = 1;
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
    i = 0;
    if (arr[i] > n)
        return (arr[i]);
    while (i < a_len && arr[i] < n)
        ++i;
    key = arr[i - 1];
    return (free(arr), key);
}

void find_cheapest_in_a(push *stack, int **cheap, int target, int a_len)
{
    (*cheap)[2] = 0;
    while (stack && stack->data != target)
    {
        (*cheap)[2] += 1;
        stack = stack->next;
    }
    if (stack && stack->data == target)
        (*cheap)[2] += 1;
    (*cheap)[3] = a_len - (*cheap)[2];
    if ((*cheap)[2] < (*cheap)[3])
    {
        (*cheap)[3] = -1;
    }
    else
    {
        (*cheap)[2] = (*cheap)[3];
        (*cheap)[3] = 1;
    }
}

int *count_push_price(push *stack_a, push *stack_b, int n, int target, int b_len)
{
    int *pos;

    printf("%d\n", target);
    pos = malloc(sizeof(int) * 4);
    if (!pos)
        return (NULL);
    pos[0] = 0;
    while (stack_b && stack_b->data != n)
    {
        pos[0] += 1;
        stack_b = stack_b->next;
    }
    if (stack_b->data == n)
        pos[0] += 1;
    pos[1] = b_len - pos[0];
    if (pos[0] < pos[1])
        pos[1] = -1;
    else if (pos[0] > pos[1])
    {
        pos[0] = pos[1];
        pos[1] = 1;
    }
    find_cheapest_in_a(stack_a, &pos, target, ft_lstsize(stack_a));
    return (pos);
}

int main(int ac, char **ar)
{
    push *n = ft_lstnew(1);
    push    *n1 = ft_lstnew(3);
    push        *n2 = ft_lstnew(8);
    push            *n3 = ft_lstnew(7);
    push                *n4 = ft_lstnew(6);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    push    *b = ft_lstnew(5);
    push    *b1 = ft_lstnew(9);
    push    *b2  = ft_lstnew(-66);
    b->next = b1;
    b1->next = b2;

    int *pos = count_push_price1(n, b, 5, detect_target(n, 5, ft_fill_arr(n), ft_lstsize(n)), ft_lstsize(b));
    printf("pos[2] = %d pos[3] = %d\n", pos[2], pos[3]);
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