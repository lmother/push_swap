#include "includes/push_swap.h"

int	ft_check_sort_a(t_stacks *stacks)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = stacks->head_a;
	while (tmp)
	{
		if (tmp->flag >= 0)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort(t_stacks *stacks)
{
	int	i;

	i = 0;
	ft_first_action(stacks);
	while (ft_check_sort_a(stacks) == 0 || stacks->size_b > 0)
	{
		if (stacks->size_b > 0)
			ft_sort_b_wile_not_empty(stacks);
		else if (stacks->head_a->flag > 0)
			ft_check_flag(stacks);
		else
		{
			ft_if_flag_zero(stacks, i);
			ft_beck_to_head(stacks);
		}
	}
}
