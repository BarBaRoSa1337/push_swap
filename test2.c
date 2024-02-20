#include "push_swap.h"

void    selsect_moves(push **stack_a, push **stack_b)
{
    push    *head;
    push    *last;
    int     pos;
    int b_len;
    int index;

    head = *stack_b;
    b_len = ft_lstsize(*stack_b);
    index = select_cheapest(*stack_a, stack_b, b_len);
    while (index--)
        head = head->next;
    pos = count_push_price(*stack_a, *stack_b, head->data, b_len);
    if (pos[1] == 1 && pos[3] == 1)
    {
        while (pos[0] > 0 && pos[2] > 0)
        {
            rra_rrb_rrr(stack_a, stack_b, "rrr");
            pos[0]--;
            pos[2]--;
        }
        while (last->data != head->data)
            rra_rrb_rrr(stack_b, &last, "rrb");
        while (pos[2]--)
            rra_rrb_rrr(sta)
        
        pa_pb(stack_a, stack_b, "pb");
    }
    else if (pos[1] == -1 && pos[3] == -1)
    {

    }
    else
    {

    }
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
    push    *b1 = ft_lstnew(6);
    push    *b2  = ft_lstnew(4);
    b->next = b1;
    b1->next = b2;

    // int *pos = count_push_price(n, b, 1);
    printf ("%d\n", select_cheapest(n, b, ft_lstsize(b)));
    // printf("pos[0] = %d, pos[1] = %d\n", pos[0], pos[1]);
    // printf("pos[2] = %d, pos[3] = %d\n", pos[2], pos[3]);

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
    ft_lstclear(&b);
    // ft_lstclear(&stack);
}
