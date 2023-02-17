#include "push_swap.h"

void    swap(int *a)
{
	int tmp;

	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void	sa(s_list *t_list)
{
	swap(t_list->stack_a);
	write(1, "sa\n", 3);
}

void	sb(s_list *t_list)
{
	swap(t_list->stack_b);
	write(1, "sb\n", 3);
}

void	ss(s_list *t_list)
{
	swap(t_list->stack_a);
	swap(t_list->stack_b);
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

void	push(int *a, int *b, int len, int b_len)
{
	int	buf[len + 1];
	int i;
	int	k;
	
	i = 0;
	k = 1;
	buf[0] = b[0];
	while (i < len)
		buf[k++] = a[i++]; 
	i = 0;
	while (i < k)
	{
		a[i] = buf[i];
		i++;
	}
	i = 0;
	while (i < b_len)
	{
		b[i]  = b[i + 1];
		i++;
	}
}

void	pa(s_list *t_list)
{
	push(t_list->stack_a, t_list->stack_b, t_list->a_len++, t_list->b_len--);
	write(1, "pb\n", 3);
}

void	pb(s_list *t_list)
{
	push(t_list->stack_b, t_list->stack_a, t_list->b_len++, t_list->a_len--);
	write(1, "pa\n", 3);
}

void	rev_rotate(int *a, int len)
{
	int i;
	int	k;
	int	tmp;
	
	i = len - 1;
	k = 0;
	tmp = a[i];
	while (k < len - 1)
	{
		k++;
		i--;
		a[i + 1] = a[i];
		a[i] = tmp;
	}
}

void	rra(s_list *t_list)
{
	rev_rotate(t_list->stack_a, t_list->a_len);
	write(1, "rra\n", 4);
}


void	rrb(s_list *t_list)
{
	rev_rotate(t_list->stack_b, t_list->b_len);
	write(1, "rrb\n", 4);
}

void	rrr(s_list *t_list)
{
	rev_rotate(t_list->stack_a, t_list->a_len);
	rev_rotate(t_list->stack_b, t_list->b_len);
	write(1, "rrr\n", 4);
}