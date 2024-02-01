
#include "push_swap.h"

int ft_doubles(int *arr, int n, unsigned int len)
{
    size_t  i;
    int     flag;

    i = 0;
    flag = 0;
    while (i < len)
    {
        if (arr[i] == n && flag)
            return (0);
        else if (arr[i] == n)
            ++flag;
        ++i;
    }
    return (1);
}

int main(int ac, char **ar)
{
    int tmp[4];
    tmp[0] = 2;
    tmp[1] = 3;
    tmp[2] = 1;
    tmp[3] = 2;
    printf ("%d",  ft_doubles(tmp, 2, 4));
}