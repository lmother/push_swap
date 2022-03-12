#include "includes/push_swap.h"

int	ft_check_sort_checker(t_stacks *list)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = list->head_a;
	if (list->size_b > 0)
		return (0);
	while (tmp->next != 0)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

t_stacks	ft_check_stack_checker(int agrc, char **str)
{
	int	*arr;
	int	len;

	len = ft_check_strs(str);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit (1);
	ft_init_array(arr, str, agrc);
	ft_check_double(arr, len);
	return (ft_init_stacks(arr, len));
}

void	ft_check_line(t_stacks *stacks, char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0 && ft_strlen(str) == 2)
		ft_sa(stacks, 0);
	else if (ft_strncmp(str, "rrr", 3) == 0 && ft_strlen(str) == 3)
		ft_rrr(stacks, 0);
	else if (ft_strncmp(str, "rrb", 3) == 0 && ft_strlen(str) == 3)
		ft_rrb(stacks, 0);
	else if (ft_strncmp(str, "rra", 3) == 0 && ft_strlen(str) == 3)
		ft_rra(stacks, 0);
	else if (ft_strncmp(str, "sb", 2) == 0 && ft_strlen(str) == 2)
		ft_sb(stacks, 0);
	else if (ft_strncmp(str, "ra", 2) == 0 && ft_strlen(str) == 2)
		ft_ra(stacks, 0);
	else if (ft_strncmp(str, "rr", 2) == 0 && ft_strlen(str) == 2)
		ft_rr(stacks, 0);
	else if (ft_strncmp(str, "pa", 2) == 0 && ft_strlen(str) == 2)
		ft_pa(stacks, 0);
	else if (ft_strncmp(str, "pb", 2) == 0 && ft_strlen(str) == 2)
		ft_pb(stacks, 0);
	else if (ft_strncmp(str, "rb", 2) == 0 && ft_strlen(str) == 2)
		ft_rb(stacks, 0);
	else if (ft_strncmp(str, "ss", 2) == 0 && ft_strlen(str) == 2)
		ft_ss(stacks, 0);
	else
		ft_print_err();
}

void	ft_read_line(t_stacks *stacks)
{
	char	*str;

	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		ft_check_line(stacks, str);
		free(str);
	}
	if (*str != '\0')
		ft_print_err();
	free(str);
}

int	main(int agrc, char **agrv)
{
	t_stacks	list;

	if (agrc < 2)
		exit (0);
	list = ft_check_stack_checker(agrc, agrv);
	ft_read_line(&list);
	if (ft_check_sort_checker(&list) == 0)
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	ft_del_stack_b(&list);
	ft_del_stack(&list);
	return (0);
}
