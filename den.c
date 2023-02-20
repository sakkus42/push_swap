#include <unistd.h>
#include <stdio.h> // printf için bunu sil
#include <stdlib.h>

typedef struct den
{
    int ind;
    struct den *next;
} t_list;

t_list  *new_stack()
{
    t_list *res = malloc(sizeof(t_list));
    res->ind = 0;
    return (res);
}

t_list *ft_func()
{
    t_list *res;
    t_list  *stack;

    res = malloc(sizeof(t_list));
    stack = res;
    for (size_t i = 0; i < 5; i++)
    {   
        res->ind = i;
        res->next = new_stack();
        res = res->next;
    }
    return (stack);
}

int main(int ac, char *arv[])
{
    // t_list *struct1;
    // struct1 = ft_func();
    // while (struct1)
    // {
    //     printf("%d", struct1->ind);
    //     struct1 = struct1->next;
    // }
    int *a;
    (void) arv;

    a = malloc(sizeof(int) * ac);
    for (int i = 0; i < ac; i++)
    {
        a[i] = i;
    }
    int j = 0;
    int kk = 0;
    while(a[j] && a[j + 1])
    {
        kk++;
    }
    printf("%d", kk);
    
}