#include "push_swap.h"

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
    push    *b1 = ft_lstnew(6);
    push    *b2  = ft_lstnew(9);
    b->next = b1;
    b1->next = b2;

    selsect_moves(&n, &b);
    selsect_moves(&n, &b);
    selsect_moves(&n, &b);
    push *head = n;
    push *stack = b;
    while (head)
    {
        printf ("1 %d\n", head->data);
        head = head->next;
    }
    while (b)
    {
        printf ("2  %d\n", b->data);
        b = b->next;
    }
    ft_lstclear(&n);
    // ft_lstclear(&b);
    ft_lstclear(&stack);
}
