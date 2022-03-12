#include "includes/push_swap.h"

void	ft_ss(t_stacks *stacks, int flag)
{
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	if (flag == 1)
		write(1, &"ss\n", 3);
}
