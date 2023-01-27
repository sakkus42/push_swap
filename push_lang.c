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