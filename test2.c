#include "push_swap.h"

// void    fix_lst(push **stack, int len)
// {
//     int tmp[2];
//     int i;
//     push    *head;
//     push    *lst;

//     i = 0;
//     head = *stack;
//     tmp[0] = head->data;
//     while (head)
//     {
//         if (head->data < tmp[0])
//         {
//             tmp[0] = head->data;
//             tmp[1] = i;
//         }
//         head = head->next;
//         ++i;
//     }
//     head = *stack;
//     lst = *stack;
//     while (lst && head->data != tmp[0])
//     {
//         if (tmp[1] <= len / 2)
//             ra_rb_rr(stack, "ra");
//         else
//             rra_rrb_rrr(stack, NULL, "rra");
//         head = *stack;
//         lst = lst->next;
//     }
// }

int *find_cheapest_in_a(push *stack, int **cheap,int data, int a_len)
{
    while (stack && data < stack->data)
    {
        cheap[2] += 1;
        stack = stack->next;
    }
    if (stack->data == data)
    {
        cheap[2] += 1;
        stack = stack->next;
    }
    cheap[3] = a_len - cheap[2];
    return (cheap);
}

int *count_push_price(push *stack_a, push *stack_b, int n)
{
    int b_len;
    int *pos;

    b_len = ft_lstsize(stack_b);
    pos = malloc(sizeof(int) * 4);
    if (!pos)
        return (NULL);
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
        pos[0] = pos[1] 
        pos[1] = 1;
    }
    find_cheapest_in_a(stack_a, &pos, n, ft_lstsize(stack_a));
    return (pos);
}

// int *perfect_push(push *stack_a, push *stack_b, int b_len)
// {
//     int     i;
//     int     *tmp;
//     char    **ins;

//     i = 0;
//     tmp = malloc(sizeof(int) * 4);
//     ins = malloc(sizeof(int *) * b_len);
//     if (!ins)
//         return (NULL);
//     b_len = ft_lstsize(stack_b);
//     while (i < b_len)
//     {
//         ins[i] = count_push_price(stack_a, stack_b, head->data);
//         ++i;
//     }
//     i = 0

//     return (ins);
// }

int main(int ac, char **ar)
{
    push *n = ft_lstnew(3);
    push    *n1 = ft_lstnew(3);
    push        *n2 = ft_lstnew(5);
    push            *n3 = ft_lstnew(2);
    push                *n4 = ft_lstnew(4);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    // push    *b = ft_lstnew(6);
    // push    *b1 = ft_lstnew(10);
    // push    *b2  = ft_lstnew(9);
    // b->next = b1;
    // b1->next = b2;

    fix_lst(&n, ft_lstsize(n));
    push *head = n;
    // move_up_down_push(&n, &b, 6, 'u');
    // push *tmp = b;
    while (head)
    {
        printf ("1  %d\n", head->data);
        head = head->next;
    }
    // while (b)
    // {
    //     printf ("2  %d\n", b->data);
    //     b = b->next;
    // }
    ft_lstclear(&n);
    // ft_lstclear(&b);
    // ft_lstclear(&stack);
}
