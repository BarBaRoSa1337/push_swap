#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

size_t	ft_atoi(const char *str)
{
	size_t	num;
	ssize_t	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num * sign);
}

push    *get_args(int ac, char **ar)
{
    int     i;
    int     j;
    push    *lst;

    i = 1;
    lst = NULL;
    while (ar[i])
    {
       ft_lstadd_front(&lst, ft_lstnew(ft_atoi(ar[i])));
       ++i;
    }
    return (lst);
}


int main(int ac, char **ar)
{
    // push *n = ft_lstnew(-11);
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
    
    push *n =  get_args(ac, ar);
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
}
