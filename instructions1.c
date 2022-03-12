#include "includes/push_swap.h"

void	ft_rb(t_stacks *stacks, int flag)
{
	t_stack	*b_head;
	t_stack	*b_tail;

	if (stacks->size_b < 2)
		return ;
	b_head = stacks->head_b->next;
	b_tail = stacks->head_b;
	b_head->prev = NULL;
	b_tail->next = NULL;
	b_tail->prev = stacks->tail_b;
	stacks->tail_b->next = b_tail;
	stacks->tail_b = b_tail;
	stacks->head_b = b_head;
	if (flag == 1)
		write(1, &"rb\n", 3);
}

void	ft_rra(t_stacks *stacks, int flag)
{
	t_stack	*a_head;
	t_stack	*a_tail;

	if (stacks->size_a < 2)
		return ;
	a_head = stacks->head_a;
	while (a_head->next != 0)
		a_head = a_head->next;
	a_tail = stacks->tail_a->prev;
	a_head->prev = NULL;
	a_tail->next = NULL;
	a_head->next = stacks->head_a;
	stacks->head_a->prev = a_head;
	stacks->tail_a = a_tail;
	stacks->head_a = a_head;
	if (flag == 1)
		write(1, &"rra\n", 4);
}

void	ft_rrb(t_stacks *stacks, int flag)
{
	t_stack	*b_head;
	t_stack	*b_tail;

	if (stacks->size_b < 2)
		return ;
	b_head = stacks->head_b;
	while (b_head->next != 0)
		b_head = b_head->next;
	b_tail = stacks->tail_b->prev;
	b_head->prev = NULL;
	b_tail->next = NULL;
	b_head->next = stacks->head_b;
	stacks->head_b->prev = b_head;
	stacks->tail_b = b_tail;
	stacks->head_b = b_head;
	if (flag == 1)
		write(1, &"rrb\n", 4);
}

void	ft_rrr(t_stacks *stacks, int flag)
{
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
	if (flag == 1)
		write(1, &"rrr\n", 4);
}

void	ft_rr(t_stacks *stacks, int flag)
{
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
	if (flag == 1)
		write(1, &"rr\n", 3);
}
