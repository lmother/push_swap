#include "includes/push_swap.h"

int	ft_max_val(t_stack *stack)
{
	int			max;
	t_stack		*tmp;

	tmp = stack;
	max = 0;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack->next)
	{
		stack = stack->next;
		if (min > stack->value)
			min = stack->value;
	}
	return (min);
}

void	ft_sort_3_digit(t_stacks *stacks)
{
	if (stacks->size_a == 2)
	{
		if (stacks->head_a->value > stacks->tail_a->value)
			ft_sa(stacks, 1);
	}
	if (stacks->size_a == 3)
	{
		if (ft_max_val(stacks->head_a) == stacks->head_a->value)
			ft_ra(stacks, 1);
		if (ft_max_val(stacks->head_a) == stacks->head_a->next->value)
			ft_rra(stacks, 1);
		if (stacks->head_a->value > stacks->head_a->next->value)
			ft_sa(stacks, 1);
	}
}

void	ft_sort_5_digit(t_stacks *stacks)
{
	int	max;
	int	min;

	max = stacks->size_a;
	min = stacks->head_a->order;
	while (stacks->size_b < 2)
	{
		if (stacks->head_a->value == max || stacks->head_a->value == min)
			ft_pb(stacks, 1);
		else
			ft_ra(stacks, 1);
	}
	ft_sort_3_digit(stacks);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
	if (stacks->head_a->value == max)
		ft_ra(stacks, 1);
	else
	{
		ft_sa(stacks, 1);
		ft_ra(stacks, 1);
	}
}

void	ft_global_sort(t_stacks *stacks)
{
	if (stacks->size_a <= 3)
		ft_sort_3_digit(stacks);
	else if (stacks->size_a <= 5)
		ft_sort_5_digit(stacks);
	else
		ft_sort(stacks);
}
