#include "push_swap.h"

int	is_sort(s_list *s_stack)
{
	int	i;
	int	k;

	i = 0;

	while (i < s_stack->a_len)
	{
		k = i + 1;
		while (k < s_stack->a_len)
		{
			if (s_stack->stack_a[i] > s_stack->stack_a[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	stack_int(int *stack_a, char **arv)
{
	int	i;
	int	k;
	int	j;
	long int	dig;

	i = 1;
	k = 0;
	while (arv[i])
	{
		j = 0;
		dig = ft_atoi(arv[i++]);
		if (dig < -2147483648 || dig > 2147483647)
			return(1);
		while (j < k)
		{
			if (stack_a[j++] == dig)
				return (1);
		}
		stack_a[k++] = (int)dig;
	}
	return (0);
}

int	stack_init(s_list *s_stack, int a_len, char **arv)
{ 
	s_stack->a_len = a_len;
	s_stack->b_len = 0;
	s_stack->stack_a = malloc(sizeof(int) * a_len);
	s_stack->stack_b = malloc(sizeof(int) * a_len);
	s_stack->sorted = malloc(sizeof(int) * a_len);
	if (!(s_stack->stack_a) && !(s_stack->stack_b) && !(s_stack->sorted))
		return (1);
	if (stack_int(s_stack->stack_a, arv) || stack_int(s_stack->sorted, arv))
		return (1);
	sort(s_stack->sorted, s_stack->a_len);
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

	if (ac < 2)
		return (1);
	if (control(arv) || stack_init(&s_stack, ac - 1, arv) || is_sort(&s_stack))
	{
		if (s_stack.stack_a)
			free(s_stack.stack_a);
		system("leaks push_swap");
		write(1, "ERROR\n", 6);
		return (1);
	}
	int i = 0;
	while(i < s_stack.a_len)
	{
		printf("%d ", s_stack.stack_a[i]);
		i++;
	}
	sort_small(&s_stack);
	printf("\n");
	i = 0;
	while(i < s_stack.a_len)
	{
		printf("%d ", s_stack.stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while(i < s_stack.b_len)
	{
		printf("%d ", s_stack.stack_b[i]);
		i++;
	}
	// system("leaks push_swap");
	return (0);
}
