#include "includes/push_swap.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\n' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

long int	ft_atoi_long(const char *str)
{
	int			i;
	long int	res;
	int			m;

	i = 0;
	m = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		m *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if ((res * m) > 2147483647 || (res * m) < -2147483648)
			ft_print_err();
		i++;
	}
	return (res * m);
}

void	ft_swap(int *arr, int left, int right)
{
	int	tmp;

	tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

void	ft_qsort_arr(int *arr, int l, int r)
{
	int	left;
	int	right;
	int	pivot;

	right = r;
	left = l;
	pivot = arr[(l + r) / 2];
	if (l < r)
	{
		while (left <= right)
		{
			while (arr[left] < pivot)
				left++;
			while (arr[right] > pivot)
				right--;
			if (left <= right)
			{
				ft_swap(arr, left, right);
				left++;
				right--;
			}
		}
		ft_qsort_arr(arr, l, right);
		ft_qsort_arr(arr, left, r);
	}
}
