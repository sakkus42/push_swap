#include "push_swap.h"

int	ft_control(char **arv)
{
	int	i;
	int	k;

	i = 0;
	while (arv[i])
	{
		k = 0;
		if (arv[i][k] == '-' || arv[i][k] == '+')
			k++;
		while (arv[i][k])
		{
			if (arv[i][k] <= '9' && arv[i][k] >= '0')
				k++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_gen_control(char **arv, int ac)
{
	char	**str;

	str = 0;
	if (ac == 2)
	{
		str = ft_split(arv[1], ' ');
		if (ft_control(str))
		{
			free(str);
			return (1);
		}
		free(str);
	}
	else if (ft_control(arv + 1))
	{
		return (1);
	}
	return (0);
}
