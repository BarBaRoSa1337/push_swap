#include "push_swap.h"

void	ft_lstadd_back1(push **lst, push *new)
{
	push	*head;

	if (!new || lst == NULL)
		return ;
	head = *lst;
	if (!head)
	{
		*lst = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}

void	ft_lstdelone1(push **lst)
{
	if (lst == NULL)
		return ;
	free (*lst);
	lst = NULL;
}
void    pa_pb(push **stack_a, push **stack_b, char *flag)
{
    int     tmp;
    push    *head;

    if (flag[1] == 'a')
    {
        head = *stack_a;
        while (head->next->next)
            head = head->next;
        tmp = head->next->data;
        ft_lstadd_back1(stack_b, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    // else if (flag[1] == 'b')
    // {
    //     head = *stack_b;
    //     while (head->next)
    //         head = head->next;
    //     tmp = head->data;
    //     ft_lstadd_back1(stack_a, ft_lstnew(tmp));
    //     ft_lstdelone(head);
    // }
    printf ("%s \n", flag);//aba!
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
    push *head = n;
    push *b = NULL;
    pa_pb(&head, &b, "pa");
    while (head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf(" ah %d\n", b->data);
    ft_lstclear(&n);
    ft_lstclear(&b);
}
