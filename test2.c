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

    head = *stack_a;
    stack_len = ft_lstsize(head);
    lis = ft_lis(head, stack_len);
    while (--stack_len)
    {
        if (is_lis(lis, stack_len, last->data))
        {
            // printf("%d\n", last->data);
            // pa_pbb(stack_a, stack_b, &last,"pb");
        }
        ra_rb_rrr (stack_a,&last, "ra");
    }
    free (lis);
}

int    push_node(push **stack_a, push **stack_b, int a_len, int b_len,char *flag)
{
    push    *head;
    int     tmp;

    if (flag[1] == 'a' && a_len == 1)
    {
        head = *stack_a;
        tmp = head->data;
        ft_lstadd_back(stack_b, ft_lstnew(tmp));
        ft_lstclear(stack_a);
        return (1);
    }
    else if (flag[1] == 'b' && b_len == 1)
    {
        head = *stack_b;
        tmp = head->data;
        ft_lstadd_back(stack_a, ft_lstnew(tmp));
        ft_lstclear(stack_b);
        return (1);
    }
    return (0);
}

void    pa_pb(push **stack_a, push **stack_b ,char *flag)
{
    int     tmp;
    push    *head;

    if (push_node(stack_a, stack_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b),flag))
        return ;
    if (flag[1] == 'a')
    {
        head = *stack_a;
        while (head->next->next)
            head = head->next;
        tmp = head->next->data;
        ft_lstadd_back(stack_b, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    else if (flag[1] == 'b')
    {
        head = *stack_b;
        while (head->next->next)
            head = head->next;
        tmp = head->next->data;
        ft_lstadd_back(stack_a, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    printf ("%s \n", flag);
}

int main(void)
{
    push *n = ft_lstnew(2);
    // push    *n1 = ft_lstnew(3);
    // push        *n2 = ft_lstnew(5);
    // push            *n3 = ft_lstnew(4);
    // push                *n4 = ft_lstnew(8);
    // n->next = n1;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    push    *b = ft_lstnew(1337);
    push *head = b;
    // push    *b1 = ft_lstnew(4242);
    // b->next = b1;
    pa_pbb(&n, &b, "pa");
    // while (head)
    // {
    //     printf("1  %d\n", head->data);
    //     head = head->next;
    // }
    while (b)
    {
        printf ("2  %d\n", b->data);
        b = b->next;  
    }
    
    // ft_lstclear(&n);
    ft_lstclear(&head);
}
