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

int	stack_init(s_list *s_stack, int a_len, char **arv)
{ 
	int			i;
	int			k;
	int			j;
	long int	dig;
	
	s_stack->a_len = a_len;
	s_stack->stack_a = malloc(sizeof(int) * a_len);
	if (!(s_stack->stack_a))
		return (1);
	i = 1;
	k = 0;
	while (arv[i])
	{
		j = 0;
		dig = ft_atoi(arv[i++]);
		if ((dig < -2147483648 || dig > 2147483647))
			return(1);
		while (j < k)
		{
			if (s_stack->stack_a[j++] == dig)
				return (1);
		}
		s_stack->stack_a[k++] = (int)dig;
	}
	return (0);
}

int	control(char **arv)
{
	int	i;
	int	k;
	
	i = 1;
	while (arv[i])
	{
		k = 0;
		if (arv[i][k] == '-' || arv[i][k] == '+')
			k++;
		while(arv[i][k])
		{
			if (!(arv[i][k] <= '9' && arv[i][k] >= '0'))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *arv[])
{
	s_list s_stack;

	if (ac < 3 || control(arv) || stack_init(&s_stack, ac - 1, arv))
	{
		if (s_stack.stack_a)
			free(s_stack.stack_a);
		system("leaks push_swap");
		write(1, "ERROR\n", 6);
		return (1);
	}
	int i = 0;
	while(i < ac - 1)
	{
		printf("%d ", s_stack.stack_a[i]);
		i++;
	}
	printf("\n");
	swap_a(s_stack.stack_a);
	i = 0;
	while(i < ac - 1)
	{
		printf("%d ", s_stack.stack_a[i]);
		i++;
	}
	// system("leaks push_swap");
	return (0);
}
