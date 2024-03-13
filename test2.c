#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

char    *get_args1(int ac, char **ar)
{
    char    *buff;
    int     len;
    int     z;
    int     j;
    int     i;

    i = 1;
    len = 0;
    while (i < ac)
        len += ft_strlen(ar[i++]);
    buff = malloc(sizeof(char) * len + ac);
    if (!buff)
        return (NULL);
    i = 1;
    z = 0;
    while (i < ac)
    {
        j = 0;
        while (ar[i][j])
            buff[z++] = ar[i][j++];
        if (i < ac)
            buff[z++] = ' ';
        ++i;
    }
    return (buff);
}

void    sort_three(push **stack_a)
{
    int *min;
    push    *head;

    head = *stack_a;
    min = get_min(head);
    if (head->next->data == min[0])
    {
        ra_rb_rr(stack_a, "ra");
        head = *stack_a;
    }
    else if (head->next->next->data == min[0])
        rra_rrb_rrr(stack_a, "rra");
    head = *stack_a;
    if (head->next->data > head->next->next->data)
        sa_sb(stack_a, "sa");
    free (min);
}

void    push_node(push **stack_a, push **stack_b, int min)
{
    push    *head;

    head = 
}

void    sort_five(push **stack_a, push **stack_b)
{
    int *min;
    int b_len;
    push    *head;

    head = *stack_a;
    while (ft_lstsize(head) > 3)
    {
        min = get_min(head);
        push_node(stack_a, stack_b, min[0]);
        free (min);
        head = *stack_a;
    }
    sort_three(stack_a);
    b_len = ft_lstsize(*stack_b);
    while (b_len--)
        stack_recovery(stack_a, stack_b);
}

int main(int ac, char **ar)
{
    push *n = ft_lstnew(2);
    push    *n1 = ft_lstnew(1);
    push        *n2 = ft_lstnew(3);
    push            *n3 = ft_lstnew(5);
    push                *n4 = ft_lstnew(7);
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    // push    *b = ft_lstnew(5);
    // push    *b1 = ft_lstnew(1);
    // push    *b2  = ft_lstnew(9);
    // b->next = b1;
    // b1->next = b2;
    
    // sort_three(&n);
   sort_three(&n);
    push *head = n;
    while (head)
    {
        printf ("%d\n", head->data);
        head = head->next;
    }
    // while (b)
    // {
    //     printf ("2  %d\n", b->data);
    //     b = b->next;
    // }
    ft_lstclear(&n);
    // ft_lstclear(&stack);
    // char *buff =  get_args1(ac, ar);
    // printf("%s\n", buff);
    // char **args = ft_split(buff, ' ');
    // int i = 0;
    // while (args[i])
    // {
    //     printf("%s\n", args[i]);
    //     ++i;
    // }
    // i = 0;
    // while (args[i])
    // {
    //     free (args[i]);
    //     ++i;
    // }
    // free (buff);
}
