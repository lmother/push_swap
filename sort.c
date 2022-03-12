#include "includes/push_swap.h"

void	ft_first_action(t_stacks *stacks)
{
	int	i;

	stacks->val = 1;
	stacks->max = stacks->size_a;
	stacks->mid = stacks->size_a / 2 + 1;
	stacks->flag++;
	i = 0;
	while (i < stacks->mid)
	{
		if (stacks->head_a->value <= stacks->mid)
		{
			ft_pb(stacks, 1);
			i++;
		}
		else
			ft_ra(stacks, 1);
	}
}

void	ft_sort_b_wile_not_empty(t_stacks *stacks)
{
	int	i;

	stacks->max = ft_max_val(stacks->head_b);
	stacks->mid = (stacks->max - stacks->val) / 2 + stacks->val;
	stacks->flag++;
	i = stacks->size_b;
	while (i--)
	{
		if (stacks->head_b->value == stacks->val
			|| stacks->head_b->value > stacks->mid)
		{
			ft_pa(stacks, 1);
			stacks->head_a->flag = stacks->flag;
			if (stacks->head_a->value == stacks->val)
			{
				ft_ra(stacks, 1);
				stacks->val++;
				stacks->tail_a->flag = -1;
			}
		}
		else
			ft_rb(stacks, 1);
	}
}

void	ft_check_flag(t_stacks *stacks)
{
	int	flag;

	flag = stacks->head_a->flag;
	while (flag == stacks->head_a->flag && stacks->head_a->flag != -1)
	{
		if (stacks->head_b && stacks->head_b->value == stacks->val)
			ft_pa(stacks, 1);
		if (stacks->size_b > 1 && stacks->head_b->next->value == stacks->val)
		{
			ft_sb(stacks, 1);
			ft_pa(stacks, 1);
		}
		if (stacks->head_a->value == (stacks->val + 1)
			&& stacks->head_a->next->value == stacks->val)
			ft_sa(stacks, 1);
		if (stacks->head_a->value == stacks->val)
		{
			stacks->val++;
			stacks->head_a->flag = -1;
			ft_ra(stacks, 1);
		}
		else
			ft_pb(stacks, 1);
	}
}

void	ft_if_flag_zero(t_stacks *stacks, int i)
{
	stacks->max = ft_max_val(stacks->head_a);
	stacks->mid = (stacks->max - stacks->val) / 2 + stacks->val;
	i = stacks->mid - stacks->val + 1;
	while (i && stacks->head_a->flag != -1)
	{
		if (stacks->head_a->value < stacks->mid)
		{
			if (stacks->tail_a->value == (stacks->head_a->value - 1))
			{
				ft_ra(stacks, 1);
				stacks->val++;
				stacks->tail_a->flag = -1;
				i--;
			}
			else
			{
				stacks->head_a->flag++;
				ft_pb(stacks, 1);
				i--;
			}
		}
		else
			ft_ra(stacks, 1);
	}
}

void	ft_beck_to_head(t_stacks *stacks)
{
	t_stack	*tmp;

	while (stacks->tail_a && stacks->tail_a->flag == 0)
	{
		if (stacks->head_b && stacks->head_b->value != stacks->val)
			ft_rrr(stacks, 1);
		else
			ft_rra(stacks, 1);
	}
	tmp = stacks->head_a;
	while (tmp)
	{
		if (tmp->flag == 0)
			tmp->flag++;
		tmp = tmp->next;
	}
}
