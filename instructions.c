#include "includes/push_swap.h"

void	ft_pb(t_stacks *stacks, int flag)
{
	t_stack	*new_head;

	new_head = stacks->head_a;
	if (!stacks->head_a)
		return ;
	stacks->head_a = stacks->head_a->next;
	if (stacks->head_a)
		stacks->head_a->prev = NULL;
	new_head->next = stacks->head_b;
	new_head->prev = NULL;
	if (stacks->head_b)
		stacks->head_b->prev = new_head;
	stacks->head_b = new_head;
	if (stacks->tail_b == NULL)
		stacks->tail_b = new_head;
	while (new_head->next != 0)
		new_head = new_head->next;
	stacks->tail_b = new_head;
	stacks->size_b++;
	stacks->size_a--;
	if (flag == 1)
		write(1, &"pb\n", 3);
}

void	ft_pa(t_stacks *stacks, int flag)
{
	t_stack	*new_head;

	new_head = stacks->head_b;
	if (!stacks->head_b)
		return ;
	stacks->head_b = stacks->head_b->next;
	if (stacks->head_b)
		stacks->head_b->prev = NULL;
	new_head->next = stacks->head_a;
	if (stacks->head_a)
		stacks->head_a->prev = new_head;
	stacks->head_a = new_head;
	if (stacks->tail_a == NULL)
		stacks->tail_a = new_head;
	while (new_head->next != 0)
		new_head = new_head->next;
	stacks->tail_a = new_head;
	stacks->size_a++;
	stacks->size_b--;
	if (flag == 1)
		write(1, &"pa\n", 3);
}

void	ft_sa(t_stacks *stacks, int flag)
{
	int	tmp_val;
	int	tmp_order;
	int	tmp_flag;

	if (!stacks->head_a || !stacks->head_a->next)
		return ;
	tmp_val = stacks->head_a->value;
	tmp_flag = stacks->head_a->flag;
	tmp_order = stacks->head_a->order;
	stacks->head_a->value = stacks->head_a->next->value;
	stacks->head_a->flag = stacks->head_a->next->flag;
	stacks->head_a->order = stacks->head_a->next->order;
	stacks->head_a->next->value = tmp_val;
	stacks->head_a->next->flag = tmp_flag;
	stacks->head_a->next->order = tmp_order;
	if (flag == 1)
		write(1, &"sa\n", 3);
}

void	ft_sb(t_stacks *stacks, int flag)
{
	int	tmp_val;
	int	tmp_order;
	int	tmp_flag;

	if (!stacks->head_b || !stacks->head_b->next)
		return ;
	tmp_val = stacks->head_b->value;
	tmp_flag = stacks->head_b->flag;
	tmp_order = stacks->head_b->order;
	stacks->head_b->value = stacks->head_b->next->value;
	stacks->head_b->flag = stacks->head_b->next->flag;
	stacks->head_b->order = stacks->head_b->next->order;
	stacks->head_b->next->value = tmp_val;
	stacks->head_b->next->flag = tmp_flag;
	stacks->head_b->next->order = tmp_order;
	if (flag == 1)
		write(1, &"sb\n", 3);
}

void	ft_ra(t_stacks *stacks, int flag)
{
	t_stack	*a_head;
	t_stack	*a_tail;

	if (stacks->size_a < 2)
		return ;
	a_head = stacks->head_a->next;
	a_tail = stacks->head_a;
	a_head->prev = NULL;
	a_tail->next = NULL;
	a_tail->prev = stacks->tail_a;
	stacks->tail_a->next = a_tail;
	stacks->tail_a = a_tail;
	stacks->head_a = a_head;
	if (flag == 1)
		write(1, &"ra\n", 3);
}
