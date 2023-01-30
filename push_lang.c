#include "push_swap.h"

void    swap(int *a)
{
	int tmp;

	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void    swap_a(int *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void    swap_b(int *a)
{
	swap(a);
	write(1, "sb\n", 3);
}

void    swap_ss(int *a, int *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	rotate(int *a, int len)
{
	int i;
	int tmp;

	i = 0;
	tmp = a[i];
	while (i < len - 1)
	{
		i++;
		a[i - 1] = a[i];
		a[i] = tmp;
	}
}

void	ra(s_list *t_list)
{
	rotate(t_list->stack_a, t_list->a_len);
	write(1, "ra\n", 3);
}


void	rb(s_list *t_list)
{
	rotate(t_list->stack_b, t_list->b_len);
	write(1, "rb\n", 3);
}

void	rr(s_list *t_list)
{
	rotate(t_list->stack_a, t_list->a_len);
	rotate(t_list->stack_b, t_list->b_len);
	write(1, "rr\n", 3);
}

void	push(int *a, int len, int add)
{
	int	k;
	int	i;

	k = len;
	i = 0;
	while (i < len)
	{
		i++;
		a[k + 1] = a[k];
		k--;
	}
}