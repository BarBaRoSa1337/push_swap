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
	// while (str[i] == '\f' || str[i] == '\t' || str[i] == '\r'
	// 	|| str[i] == '\n' || str[i] == ' ' || str[i] == '\v')
	// {
	// 	++i;
	// }
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

int main(int ac, char **ar)
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

    push *stack = get_args(ac, ar);
    push *head = stack;
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
    ft_lstclear(&b);
    ft_lstclear(&stack);
}
