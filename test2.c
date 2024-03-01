#include "push_swap.h"


void find_cheapest_in_a(push *stack, int **cheap, int target, int a_len)
{
    push    *head;

    (*cheap)[2] = 0;
    while (stack && stack->data != target)
    {
        (*cheap)[2] += 1;
        stack = stack->next;
    }
    if (stack->data ==  target)
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

    pos = malloc(sizeof(int) * 4);
    if (!pos)
        return (NULL);
    pos[0] = 0;
    while (stack_b && stack_b->data != n)
    {
        pos[0] += 1;
        stack_b = stack_b->next;
    }
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
    push *n = ft_lstnew(2);
    push    *n1 = ft_lstnew(3);
    push        *n2 = ft_lstnew(7);
    push            *n3 = ft_lstnew(8);
    push                *n4 = ft_lstnew(10);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    push    *b = ft_lstnew(5);
    push    *b1 = ft_lstnew(1);
    push    *b2  = ft_lstnew(9);
    b->next = b1;
    b1->next = b2;

    int *pos = count_push_price1(n, b, 4, 3, ft_lstsize(b));
    printf ("%d %d\n", pos[2], pos[3]);
    push *head = n;
    push *stack = b;
    // while (head)
    // {
    //     printf ("1 %d\n", head->data);
    //     head = head->next;
    // }
    // while (b)
    // {
    //     printf ("2  %d\n", b->data);
    //     b = b->next;
    // }
    ft_lstclear(&n);
    ft_lstclear(&stack);
}
