#include "push_swap.h"

void    rra_rrb_rrr(push **stack, push **last,char *flag)
{
    push    *head;
    push    *tmp;

    head = *stack;
    while (head->next->next)
        head = head->next;
   tmp = head;
   *last = tmp;
   head->next->next = *stack;
   *stack = tmp->next;
   tmp->next = NULL;
}

void    ra_rb_rr(push **stack, push **last,char *flag)
{
    push    *head;
    push    *tmp;

    head = *stack;
    tmp = head->next;
    while (head)
        head = head->next;
    head->next = *stack;
    head->next->next = NULL;
    *stack = tmp;
}

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
    push *last;
    push *aba;
    ra_rb_rr(&head, &last, "rn");
    while (head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    // ft_lstclear(&last);
}
