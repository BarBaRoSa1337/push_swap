#include "push_swap.h"

int is_sorted(push *stack)
{
    int lst_size;

    lst_size = ft_lstsize(stack);
    while(lst_size--)
    {
        if (stack->data < stack->next->data)
            stack = stack->next;
        else
            return (0);
    }
    return (1);
}
int find_node(push *lst, int n)
{
    int i;

    i = 0;
    while (lst && lst->data != n)
    {
        lst = lst->next;
        ++i;
    }
    return(i);
}

int is_lis(int *arr, int len,int n)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (arr[i] == n)
            return (1);
        ++i;
    }
    return (0);
}

// void    move_up_down_push(push **stack_a, push **stack_b, int n,char flag)
// {
//     int pos;
//     push *last;
//     int len;
//     int i;

//     i = 0;
//     len = ft_lstsize(*stack_b);
//     pos = find_node(*stack_b, n);
//     if (flag == 'u')
//     {
//         while (i < len - pos)
//         {
//             rra_rrb_rrr(stack_a, &last,"rra");
//             pa_pb(stack_a, stack_b, "pb");
//             ++i;
//         }
//     }
//     if (flag == 'd')
//     {
//         while (i < pos + 1)
//         {
//             ra_rb_rr(stack_a, &last,"rb");
//             pa_pb(stack_a, stack_b, "pb");
//             ++i;
//         }
//     }
// }

void    ra_rb_rrr(push **stack, char *flag)
{
    push    *head;
    push    *tmp;

    head = *stack;
    tmp = head->next;
    while (head->next)
    {
        head = head->next;
    }
    head->next = *stack;
    // *last = head->next;
    *stack = tmp;
    head->next->next = NULL;
    printf("%s\n", flag);
}

void    filter_lst(push **stack_a, push **stack_b)
{
    int     stack_len;
    int     tmp;
    push    *last;
    push    *head;
    int     *lis;

    stack_len = ft_lstsize(head);
    tmp = stack_len;
    lis = ft_lis(head, &stack_len);
    while (tmp--)
    {
        // head = *stack_a;
        // last = find_last_node(head);
        // if (is_lis(lis, stack_len, last->data))
        // {
        //     // printf("%d\n", last->data);
        //     pa_pb(stack_a, stack_b ,"pa");
        // }
        // else
            ra_rb_rrr (stack_a, "ra");
    }
    free (lis);
}

int main(void)
{
    push *n = ft_lstnew(2);
    push    *n1 = ft_lstnew(3);
    push        *n2 = ft_lstnew(9);
    push            *n3 = ft_lstnew(5);
    push                *n4 = ft_lstnew(8);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    push    *b = ft_lstnew(1337);
    push *head = n;
    // push    *b1 = ft_lstnew(4242);
    // b->next = b1;
    filter_lst(&head, &b);
    while (head)
    {
        printf("1  %d\n", head->data);
        head = head->next;
    }
    while (b)
    {
        printf ("2  %d\n", b->data);
        b = b->next;  
    }
    
    // ft_lstclear(&n);
    ft_lstclear(&head);
}
