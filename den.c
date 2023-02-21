    // #include <unistd.h>
    // #include <stdio.h> // printf için bunu sil
    // #include <stdlib.h>

    // typedef struct den
    // {
    //     int ind;
    //     struct den *next;
    // } t_list;

    // t_list  *new_stack()
    // {
    //     t_list *res = malloc(sizeof(t_list));
    //     res->ind = 0;
    //     res->next = 0;
    //     return (res);
    // }

    // t_list *ft_func()
    // {
    //     t_list *res;
    //     t_list  *stack;

    //     res = malloc(sizeof(t_list));
    //     stack = res;
    //     for (size_t i = 0; i < 5; i++)
    //     {   
    //         res->ind = i;
    //         res->next = new_stack();
    //         res = res->next;
    //     }
    //     return (stack);
    // }

    // void    ft_free(t_list *struct1)
    // {
    //     t_list *str;
    //     int is;
        
    //     is = 1;
    //     str = struct1;
    //     while (str)
    //     {
    //         is = 1;
    //         if (!(str->next))
    //         {
    //             free(str);
    //             str = struct1;
    //             is = 0;
    //         }
    //         if (is)
    //             str = str->next;
    //     }
    // }

    // int main(int ac, char *arv[])
    // {
    //     t_list *struct1;
    //     t_list *str;
    //     struct1 = ft_func();
    //     str = struct1;
    //     while (str)
    //     {
    //         printf("%d", str->ind);
    //         str = str->next;
    //     }
    //     ft_free(struct1);
    //     while (struct1)
    //     {
    //         printf("%d", struct1->ind);
    //         struct1 = struct1->next;
    //     }
    // }