#include "includes/push_swap.h"

void	ft_free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_init_array(int *arr, char **str, int len)
{
	int		i;
	int		k;
	int		j;
	char	**tmp;

	i = 1;
	j = 0;
	while (i < len)
	{
		k = 0;
		tmp = ft_split(str[i], ' ');
		while (tmp[k])
		{
			arr[j] = ft_atoi_long(tmp[k]);
			j++;
			k++;
		}
		ft_free_strs(tmp);
		i++;
	}
}

void	ft_check_double(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				arr = NULL;
				ft_print_err();
			}
			j++;
		}
		i++;
	}
}

int	ft_check_sort(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (i);
}
