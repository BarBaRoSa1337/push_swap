#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

ssize_t	ft_atoi(const char *str)
{
	ssize_t	sign;
	ssize_t	num;
	int	    i;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
        {
			sign = -1;
        }
		++i;
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num * sign);
}

int check_doubles(int ac, char **ar)
{
    ssize_t a;
    ssize_t b;
    int     i;
    int     j;

    i = 1;
    while (i < ac)
    {
        j = 1;
        if (ft_atoi(ar[i]) > INT_MAX || ft_atoi(ar[i]) < INT_MIN)
                return (0);
        while (j < ac)
        {
            if ((i != j) && (ft_atoi(ar[i]) == ft_atoi(ar[j])))
                return (0);
            ++j;
        }
        ++i;
    }
    return (1);
}

// void    sort_less_than_ten(t_push **stack_a, t_push **stack_b, int a_len, int b_len)
// {
//     int i;

//     i = 0;
//     while (i < a_len / 2)
//     {
//         pa_pb(stack_a, stack_b, "pb");
//         ++i;
//     }
//     a_len = ft_lstsize(*stack_a);
//     if (a_len == 5)
//         sort_five(stack_a, stack_b);
//     else if ()
// }

int main(int ac, char **ar)
{
    printf ("%d\n", check_doubles(ac, ar));
}
