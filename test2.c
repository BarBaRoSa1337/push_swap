#include "push_swap.h"

// int is_lis(int *arr, int len,int n)
// {
//     int i;

//     i = 0;
//     while (i < len)
//     {
//         if (arr[i] == n)
//             return (1);
//         ++i;
//     }
//     return (0);
// }

// void    filter_lst(push **stack_a, push **stack_b)
// {
//     int     stack_len;
//     int     tmp;
//     push    *last;
//     push    *head;
//     int     *lis;

//     head = *stack_a;
//     stack_len = ft_lstsize(head);
//     tmp = stack_len;
//     lis = ft_lis(head, &stack_len);
//     while (tmp--)
//     {
//         head = *stack_a;
//         last = find_last_node(head);
//         if (!is_lis(lis, stack_len, last->data))
//         {
//             pa_pb(stack_a, stack_b ,"pa");
//         }
//         ra_rb_rr (stack_a, "ra");
//     }
//     free (lis);
// }

int ft_max(push *stack)
{
    int tmp;

    if (!stack)
        return (0);
    tmp = stack->data;
    while (stack)
    {
        if (stack->data > tmp)
            tmp = stack->data;
        stack = stack->next;
    }
    return (tmp);   
}

int *count_push_price(push *stack, int n)
{
    int *pos;

    pos = malloc(sizeof(int) * 2);
    while (stack && stack->data != n)
    {
        pos[0] += 1;
        stack = stack->next;
    }
    if (stack->data = n)
    {
        pos[0] += 1;
        stack = stack->next;
    }
    while (stack)
    {
        pos[1] += 1;
        stack = stack->next;
    }
    return (pos);
}

void    move_up_down_push(push **stack_a, push **stack_b, int n, char flag)
{
    push    *last;

    last = find_last_node(*stack_b);
    if (flag == 'u')
    {
        while (last->data != n)
            rra_rrb_rrr(stack_b, &last, "rrb");
        if (last->data == n)
            pa_pb(stack_a, stack_b, "pb");
    }
    if (flag == 'd')
    {
        while (last->data != n)
        {
            ra_rb_rr(stack_b, "rb");
            last = find_last_node(*stack_b);
        }
        if (last->data == n)
            pa_pb(stack_a, stack_b, "pb");
    }
}

void    stack_recovery(push **stack_a, push **stack_b, int len)
{
    int max;
    int *pos;
    push    *last;

    len = ft_lstsize(*stack_a);
    while (len)
    {
        last = find_last_node(*stack_a);
        max = ft_max(*stack_b);
        if (last->data < max)
        {
            pos = count_push_price(*stack_b, max);
            if (pos[0] < pos[1])
                move_up_down_push(stack_a, stack_b, max,'d');
            else
                move_up_down_push(stack_a, stack_b, max,'u');
            free (pos);
            len++;
        }
        else
        {
            rra_rrb_rrr(stack_a, &last, "rra");
            --len;
        }
    }
}

int main(void)
{
    push *n = ft_lstnew(2);
    push    *n1 = ft_lstnew(3);
    push        *n2 = ft_lstnew(5);
    push            *n3 = ft_lstnew(7);
    push                *n4 = ft_lstnew(8);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    push    *b = ft_lstnew(6);
    push    *b1 = ft_lstnew(10);
    push    *b2  = ft_lstnew(9);
    b->next = b1;
    b1->next = b2;

    stack_recovery(&n, &b, ft_lstsize(n));
    push *head = n;
    // move_up_down_push(&n, &b, 6, 'u');
    push *tmp = b;
    while (head)
    {
        printf ("1  %d\n", head->data);
        head = head->next;
    }
    while (b)
    {
        printf ("2  %d\n", b->data);
        b = b->next;
    }
    ft_lstclear(&n);
    ft_lstclear(&tmp);
}
