#include "includes/push_swap.h"

t_stacks	ft_init_stacks(int *arr, int size)
{
	t_stacks	res;
	int			i;
	int			j;
	int			*tmp_arr;

	i = -1;
	tmp_arr = ft_copy_arr(arr, size);
	res = ft_create_list();
	ft_qsort_arr(arr, 0, --size);
	while (++i <= size)
	{
		j = 0;
		while (j <= size)
		{
			if (tmp_arr[i] == arr[j])
			{
				ft_add_stacks(&res, j + 1, i + 1);
				break ;
			}
			j++;
		}
	}
	free(tmp_arr);
	free(arr);
	return (res);
}

void	ft_print_err(void)
{
	write (1, "Error\n", 6);
	exit(1);
}

int	ft_check_str(char **str)
{
	int	i;
	int	j;
	int	nbr;

	i = -1;
	while (str[++i])
	{
		j = 0;
		nbr = 0;
		if (ft_check_str_2(str[i], j, nbr) == 1)
			return (1);
	}
	return (0);
}

int	ft_check_strs(char **str)
{
	int		i;
	int		len_arr;
	char	**tmp;

	i = 0;
	len_arr = 0;
	while (str[++i])
	{
		tmp = ft_split(str[i], ' ');
		if (ft_check_str(tmp) == 1)
		{
			ft_free_strs(tmp);
			ft_print_err();
		}
		else
		{
			len_arr += ft_strslen(tmp);
			ft_free_strs(tmp);
		}
	}
	return (len_arr);
}

t_stacks	ft_check_stack(int agrc, char **str)
{
	int	*arr;
	int	len;

	len = ft_check_strs(str);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit (1);
	ft_init_array(arr, str, agrc);
	ft_check_double(arr, len);
	if (ft_check_sort(arr, len))
	{
		free(arr);
		exit (0);
	}
	return (ft_init_stacks(arr, len));
}
