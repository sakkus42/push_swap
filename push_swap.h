#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h> // printf için bunu sil
#include <stdlib.h>

typedef struct stack 
{
	int	*stack_a;
	int	*stack_b;
	int	a_len;
	int b_len;
}	s_list;

void    swap_a(int *a);
void    swap_b(int *a);
void    swap_ss(int *a, int *b);

#endif
