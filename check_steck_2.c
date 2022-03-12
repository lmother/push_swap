#include "includes/push_swap.h"

int	ft_check_str_2(char *str, int j, int nbr)
{
	int	k;

	k = 0;
	while (str[j])
	{
		if ((str[j] == ' ' || str[j] == '\t') && nbr == 0)
			j++;
		else if ((str[j] == '-' || str[j] == '+') && nbr == 0)
		{
			j++;
			if (++k > 1)
				return (1);
		}
		else if (ft_isdigit(str[j++]))
		{
			if (nbr++ > 10)
				return (1);
		}
		else
			return (1);
	}
	if (nbr == 0)
		return (1);
	return (0);
}
