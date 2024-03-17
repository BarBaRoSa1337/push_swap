/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:16:50 by achakour          #+#    #+#             */
/*   Updated: 2024/03/16 11:53:14 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)// too manyy functions
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

ssize_t	*char_to_arr(char **buff, int *length)
{
	ssize_t	*arr;
	int		len;
	int		i;

	i = 0;
	if (!buff || !buff[0])
		return (NULL);
	while (buff[i])
	{
		++len;
		++i;
	}
	arr = malloc(sizeof(ssize_t) * len);
	if (!arr)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		arr[i] = ft_atoi(buff[i]);
		++i;
	}
	*length = len;
	return (arr);
}

int	is_doubled(ssize_t *arr, ssize_t n, int index, int len)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (arr[i] == n)
		{
			return (0);
		}
		++i;
	}
	if (i == index && arr[i] == n)
	{
		++i;
	}
	while (i < len)
	{
		if (arr[i] == n)
		{
			return (0);
		}
		++i;
	}
	return (1);
}

ssize_t	ft_atoi(const char *str)
{
	ssize_t	sign;
	size_t	num;
	int		i;

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

int	is_valid_args(int ac, char **ar)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		return (1);
	while (ar[i])
	{
		j = 0;
		while (ar[i][j])
		{
			if (ar[i][j + 1] && (ar[i][j] == '-' || ar[i][j] == '+') && (ar[i][j
					+ 1] == '+' || ar[i][j + 1] == '-'))
				return (0);
			else if (ar[i][j + 1] && ft_isdigit(ar[i][j]) && !ft_isdigit(ar[i][j
					+ 1]))
				return (0);
			else if (!ft_isdigit(ar[i][j]) && (ar[i][j] != '-'
					&& ar[i][j] != '+'))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	is_doubled_or_max_min(ssize_t *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] < INT_MIN || arr[i] > INT_MAX || is_doubled(arr, arr[i], i,
				len))
			return (0);
		++i;
	}
	return (1);
}

char	*get_args1(int ac, char **ar)
{
	char	*buff;
	int		len;
	int		z;
	int		j;
	int		i;

	i = 1;
	len = 0;
	while (i < ac)
		len += ft_strlen(ar[i++]);
	buff = (char *)malloc(sizeof(char) * len + ac);
	if (!buff)
		return (NULL);
	i = 1;
	z = 0;
	while (i < ac)
	{
		j = 0;
		while (ar[i][j])
			buff[z++] = ar[i][j++];
		if (i < ac)
			buff[z++] = ' ';
		++i;
	}
	return (buff);
}

int process_args(t_push **lst, char *buff)
{
	char	**args;
	ssize_t	*arr;
	int		len;
	int		i;

	i = 0;
	// if (!buff)
	// 	return (free (buff), 0);
	args = ft_split(buff, ' ');
	arr = char_to_arr(args, &len);
	if (is_doubled_or_max_min(arr, len))
		return (0);
	while (i < len)
	{
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(args[i])));
		++i;
	}
	i = 0;
	while (i < len)
	{
		free(args[i]);
		++i;
	}
	free(args);
	free(buff);
	free (arr);
	return (1);
}
