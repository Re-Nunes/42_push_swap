void	ft_index_stack(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		count;

	if (!a || !a->head)
		return ;
	current = a->head;
	while (current)
	{
		count = 0;
		compare = a->head;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}