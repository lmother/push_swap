#include "includes/push_swap.h"

int	main(int agrc, char **agrv)
{
	t_stacks	list;

	if (agrc < 2)
		exit (1);
	list = ft_check_stack(agrc, agrv);
	ft_global_sort(&list);
	ft_del_stack(&list);
	return (0);
}
