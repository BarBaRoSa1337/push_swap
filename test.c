#include "push_swap.h"

char    **get_chars(int ac, char **ar)
{
    char    **buff;
    char    *tmp;
    int     i;

    i = 1;
    while (i < ac)
    {
        tmp = ft_strjoin(tmp, ar[i]);
        ++i;
    }
    buff = ft_split(tmp, ' ');
    return (free (tmp), buff);
}

int main(int ac, char **ar)
{
    char **buff = get_chars(ac, ar);
    // int i = 0;
    // while (buff[i])
    // {
    //     printf("%s\n", buff[i]);
    //     ++i;
    //     /* code */
    // }
    
}