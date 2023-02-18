#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	number;

	sign = 1;
	number = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		number = (number * 10) + (str[i] - 48) * sign;
		i++;
	}
	return (number);
}

void	sort(int *sorted, int len)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (sorted[i] > sorted[k])
			{
				tmp = sorted[i];
				sorted[i] = sorted[k];
				sorted[k] = tmp;
			}
			k++;
		}
		i++;
	}
}