#include "push_swap.h"
int *modify_arr(int *arr, int n, int len);
void    select_move2(push **stack_a, push **stack_b, int *pos)
{
    push    *last;

        if (pos[1] == 1)
            while (pos[0] > 0 && pos[0]--)
                rra_rrb_rrr(stack_a, &last, "rrb");
        else if (pos[1] == -1)
            while (pos[0] > 0 && pos[0]--)
                ra_rb_rr(stack_a, "rrb");
        if (pos[3] == 1)
            while (pos[2] > 0 && pos[2]--)
                rra_rrb_rrr(stack_a, &last, "rra");
        else if (pos[3] == -1)
            while  (pos[2] > 0 && pos[2]--)
                ra_rb_rr(stack_a, "ra");
        pa_pb(stack_a, stack_b, "pb");
}

void    select_move1(push **stack_a, push **stack_b, int *pos)
{
    push    *last;
    int *arr = ft_fill_arr(*stack_a);

    if (pos[1] == 1 && pos[3] == 1)
    {
        while (pos[0] > 0 && pos[2] > 0 && pos[0]-- && pos[2]--)
            rr_rrr(stack_a, stack_b, "rrr");
        while (pos[0] > 0 && pos[0]--)
            rra_rrb_rrr(stack_b, &last, "rrb");
        while (pos[2] > 0 && pos[2]--)
            rra_rrb_rrr(stack_a , &last, "rra");
        modify_arr(arr, last->data, ft_lstsize(*stack_a) + 1);
        pa_pb(stack_a, stack_b, "pb");
    }
    else if (pos[1] == -1 && pos[3] == -1)
    {
        while (pos[0] > 0 && pos[2] > 0 && pos[0]-- && pos[2]--)
            rr_rrr(stack_a, stack_b, "rrr");
        while (pos[0] > 0 && pos[0]--)
            ra_rb_rr(stack_b, "rb");
        while (pos[2] > 0 && pos[2]--)
            ra_rb_rr(stack_a, "ra");
        pa_pb(stack_a, stack_b, "pb");
    }
    else
        select_move2(stack_a, stack_b, pos);
}

void    selsect_moves(push **stack_a, push **stack_b, int *arr)
{
    push    *head;
    int     *pos;
    int b_len;
    int index;

    head = *stack_b;
    b_len = ft_lstsize(*stack_b);
    index = select_cheapest(*stack_a, *stack_b, arr ,b_len);
    while (index--)
        head = head->next;
    pos = count_push_price(*stack_a, *stack_b, head->data, arr,b_len);
    select_move1(stack_a, stack_b, pos);
    free (pos);
}

int put_numbr_inplace(int *arr, int n, int len)
{
    int i;

    i = 0;
    while (i < len && arr[i + 1] && arr[i + 1] < n)
        ++i;
    return (arr[i]);
}

int *modify_arr(int *arr, int n, int len)
{
    int *new;
    int i;
    int j;

    i = 0;
    j = 0;
    new = malloc(sizeof(int) * len + 1);
    if (!new)
        return (0);
    while (arr[i] && j < len  && arr[i] < n)
        new[j++] = arr[i++];
    if (arr[i] > n)
        new[j++] = n;
    while (arr[i])
        new[j++] = arr[i++];
    if (new[j - 1] < n)
        new[j] = n;
    return (free (arr), new);
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
    push    *b2  = ft_lstnew(9);
    b->next = b1;
    b1->next = b2;

    int *arr = ft_fill_arr(n);
    for (int i = 0; i < ft_lstsize(n); i++)
    {
        printf("1..%d\n", arr[i]);
    }
    arr = modify_arr(arr, 4, ft_lstsize(n));
    for (int i = 0; i < ft_lstsize(n) + 1; i++)
    {
        printf("2....%d\n", arr[i]);
    }
    free (arr);
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
