#include "includes/push_swap.h"

int	*ft_copy_arr(int *arr, int size)
{
	int	*res;
	int	i;

	i = -1;
	res = (int *)malloc(sizeof(int) * size);
	if (!res)
		exit (1);
	while (++i < size)
		res[i] = arr[i];
	return (res);
}

void	ft_del_stack(t_stacks *list)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = (*list).head_a;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
}

t_stacks	ft_create_list(void)
{
	t_stacks	new;

	new.size_a = 0;
	new.size_b = 0;
	new.flag = 0;
	new.mid = 0;
	new.val = 0;
	new.max = 0;
	new.head_a = NULL;
	new.tail_a = NULL;
	new.head_b = NULL;
	new.tail_b = NULL;
	return (new);
}

void	ft_add_stacks(t_stacks *list, int val, int order)
{
	t_stack	*a;

	a = (t_stack *) malloc(sizeof(t_stack));
	if (!a)
		exit (0);
	a->value = val;
	a->order = order;
	a->flag = 0;
	a->next = NULL;
	a->prev = list->tail_a;
	if (list->tail_a)
		list->tail_a->next = a;
	list->tail_a = a;
	if (list->head_a == NULL)
		list->head_a = a;
	list->size_a++;
}

void	ft_del_stack_b(t_stacks *list)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = (*list).head_b;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
}
