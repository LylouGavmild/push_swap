/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:17:03 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:26:19 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{	
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_isspace(int c)
{
	return (c == 32 || c == 9);
}

int	args_check(char **argv)
{
	int	i;
	int	j;
	int	space;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		space = 0;
		if (argv[i][0] == '\0')
			return (0);
		while (argv[i][++j])
		{
			if (ft_issign_or_space(argv[i][j]))
				space++;
			if ((!ft_isdigit(argv[i][j]) && !ft_issign_or_space(argv[i][j])) ||
				(ft_isdigit(argv[i][j]) && ft_issign(argv[i][j + 1])) ||
				(ft_issign(argv[i][j]) && ft_issign(argv[i][j + 1])) ||
				(ft_issign(argv[i][j]) && ft_isspace(argv[i][j + 1])))
				return (0);
		}
		if (space == j)
			return (0);
	}
	return (1);
}

long long	ft_itoem(long long i, t_frst *a)
{
	if (i > INT_MAX || i < INT_MIN)
		error_free(a);
	return (i);
}

// int	cchecker(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]) && str[i] != 32 && str[i] != 9)
// 			return (write(2, "Error: wrong argument found\n", 28), 0);
// 		i++;
// 	}
// 	return (1);
// }

// int	empty_or_not(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	schecker(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i + 1])
// 	{
// 		if (s[i] >= '0' && s[i] <= '9' && (s[i + 1] == 43 || s[i + 1] == 45))
// 			error();
// 		if (ft_isdigit(s[i]))
// 			return (0);
// 		i++;
// 	}
// 	error();
// 	return (1);
// }
