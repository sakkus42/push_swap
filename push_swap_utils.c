#include "push_swap.h"

int arrays_len(char **str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

long int *arrays_atoi(char **str)
{
    long int	*res;
    int			len;
    int			i;

    len = arrays_len(str);
    res = malloc(sizeof(long int) * len);
    if (!res)
        return (0);
    i = 0;
    while (str[i])
    {
        res[i] = ft_atoi(str[i]);
        i++;
    }
    return (res);
}