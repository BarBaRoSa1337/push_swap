#include "push_swap.h"

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

void    pa_pbb(push **stack_a, push **stack_b, push **last,char *flag)
{
    int     tmp;//thid function dont handle lstsize == 1//
    push    *head;

    if (flag[1] == 'a')
    {
        head = *stack_a;
        while (head->next->next)
            head = head->next;
        *last = head;
        tmp = head->next->data;
        ft_lstadd_back(stack_b, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    else if (flag[1] == 'b')
    {
        head = *stack_b;
        while (head->next->next)
            head = head->next;
        *last = head;
        tmp = head->next->data;
        ft_lstadd_back(stack_a, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    printf ("%s \n", flag);
}

void    ra_rb_rrr(push **stack, push **last,char *flag)
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
    *last = head->next;
    *stack = tmp;
    head->next->next = NULL;
    printf("%s\n", flag);
}

void    filter_lst(push **stack_a, push **stack_b)
{
    int     stack_len;
    push    *last;
    push    *head;
    int     *lis;

    stack_len = ft_lstsize(*stack_a) + 1;
    lis = ft_lis(*stack_a, stack_len);
    while (--stack_len)
    {
        if (is_lis(lis, stack_len, last->data))
            pa_pbb(stack_a, stack_b, &last,"pa");
        // printf("befor = %d\n", head->data);
        ra_rb_rrr (stack_a,&last, "ra");
    }
    free (lis);
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
    push    *last = NULL;
    push *head = n;
    push    *b;
    filter_lst(&head, &b);
    while (head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    // while (b)
    // {
    //     printf("%d\n", b->data);
    //     b = b->next;
    // }
    // ft_lstclear(&n);
    // ft_lstclear(&b);
}
