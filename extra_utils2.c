
void	ft_perror(t_push **lst)
{
	ft_putchar("Error");
	ft_lstclear(lst);
	return ;
}

int	is_descending(t_push *stack)
{
	t_push	*head;
	int		len;

	head = stack;
	len = ft_lstsize(stack) - 1;
	while (head && head->next && head->data > head->next->data)
	{
		head = head->next;
		--len;
	}
	if (len == 0)
		return (1);
	return (0);
}
