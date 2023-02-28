#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h> // printf için bunu sil
#include <stdlib.h>

typedef struct s_list
{
	int		value;
	int		index;
	int		target_position;
	int		position;
	int		cost_a;
	int		cost_b;
	struct	s_list	*next;
}					t_list;

t_list		*fill_to_stack(char **arv, int ac);
t_list		*new_struct(char *str);
t_list		*stack_creat(t_list *stack_a);
int			ft_gen_control(char **arv, int ac);
int			ft_numeric_cntrl(t_list *stack_a);
long int	ft_atoi(char *str);
char		**ft_split(char const *s, char c);
void		free_str(char **str);
void		exit_fail(t_list **stack_a);
int			get_size(t_list **stack);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		sb(t_list **stack);
void		sa(t_list **stack);
void		rotate(t_list **stack);
void		ra(t_list **stack);
void		rb(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
void		reverse_rotate(t_list **stack);
void		rra(t_list **stack);
void		rrb(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);
void		indexing(t_list **stack);
void		get_target_pos(t_list **stack_a, t_list **stack_b);
void		do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b);
void		set_pos(t_list **stack);
int			is_sorted(t_list **stack);
int			rep_nbr(t_list **stack_a);
void		do_chp_move(t_list **stack_a, t_list **stack_b);
void		set_cost(t_list **stack_a, t_list **stack_b);
int			get_low_pos(t_list **stack);
void		free_stack(t_list **stack);

#endif
