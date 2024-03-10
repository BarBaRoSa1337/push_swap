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

    if (ac < 1)
        return (NULL);
    i = 1;
    while (i < ac)
    {
        len += ft_strlen(ar[i]);
        ++i;
    }
    buff = malloc(sizeof(char) * len + 1);
    if (!buff)
        return (NULL);
    i = 1;
    z = 0;
    while (i < ac)
    {
        j = 0;
        while (ar[i][j])
        {
            buff[z] = ar[i][j];
            ++z;
            ++j;
        }
        ++i;
    }
    return (buff);
}

int main(int ac, char **ar)
{
    push *n = ft_lstnew(-11);
    // push    *n1 = ft_lstnew(3);
    // push        *n2 = ft_lstnew(4);
    // push            *n3 = ft_lstnew(5);
    // push                *n4 = ft_lstnew(7);
    // n->next = n1;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // push    *b = ft_lstnew(5);
    // push    *b1 = ft_lstnew(1);
    // push    *b2  = ft_lstnew(9);
    // b->next = b1;
    // b1->next = b2;
    
    // char *buff =  get_args1(ac, ar);
    printf ("%d \n", ft_lstsize(n));
    ft_lstdelone(&n);
    // push *head = n;
    // while (head)
    // {
    //     printf ("%d\n", head->data);
    //     head = head->next;
    // }
    // while (b)
    // {
    //     printf ("2  %d\n", b->data);
    //     b = b->next;
    // }
    // ft_lstclear(&n);
    // ft_lstclear(&stack);
    // free (buff);
}
