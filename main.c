#include "push_swap.h"
#include <stdio.h>

int	is_same_nbr(long int *nbrs, int len)
{
	int	i;
	int	k;

	i = 0;
	while (i < len)
	{
		k = i;
		while(k++ < len)
		{
			if (nbrs[i] == nbrs[k])
				return (1);
		}
		i++;
	}
	free(nbrs);
	return (0);
}

int	is_dignbr(char **str)
{
	int i;
	int k;
	int is;

	is = 0;
	i = 1;
	k = 0;
	while (str[i] != 0)
	{	
		if (str[i][k] == '-' && k == 0)
			k++;
		if (str[i][k] == '\0')
		{
			k = 0;
			i++;
		}
		if (str[i] && !ft_isdigit(str[i][k]))
			is = 1;
		k++;
	}
	if (is == 1)
		ft_printf("ERROR: only integers are valid!\n");
	return (is == 1);
}

int	is_intlimit(long int *nbrs, int len)
{
	int	i;
	int	is;

	i = 0;
	is = 0;
	while (i < len)
	{
		if (nbrs[i] > 2147483647 || nbrs[i] < -2147483648)
		{
			ft_printf("ERROR: given values are not integer value ranges\n");
			is = 1;
		}
		i++;
	}
	free(nbrs);
	return (is == 1);
}

int	control(char **arv, int ac)
{
	if (ac == 1)
	{
		ft_printf("ERROR: missing argument!\n");
		return (1);
	}
	if (is_dignbr(arv) || is_intlimit(arrays_atoi(arv + 1), arrays_len(arv + 1)))
		return (1);
	if (is_same_nbr(arrays_atoi(arv + 1), arrays_len(arv + 1)))
	{
		ft_printf("ERROR: not more than one of the same number\n");
		return(1);
	}
	return (0);
}

int	main(int ac, char *arv[])
{
	if (control(arv, ac))
		return (1);
	return (0);
}
	