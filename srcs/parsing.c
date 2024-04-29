/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:18:33 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:27:02 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static const char	*skip_whitespace(const char *str)
{
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	return (str);
}

static long	long	ft_atoi(const char *str, int sign)
{
	long long	number;

	number = 0;
	while (ft_isdigit(*str))
	{
		if (number > (LLONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * sign);
}

long long	ft_atocoi(const char *str)
{
	long long	sign;

	sign = 1;
	str = skip_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	return (ft_atoi(str, sign));
}

// long long	ft_atocoi(const char *nptr)
// {
// 	long long	nb;
// 	long long	i;
// 	int			sign;

// 	nb = 0;
// 	i = 0;
// 	sign = 1;
// 	while ((nptr[i]) && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
// 		i++;
// 	if (nptr[i] == '-')
// 		sign = -1;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 		i++;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 		error();
// 	while ((nptr[i]) && nptr[i] >= '0' && nptr[i] <= '9')
// 	{
// 		if (nb > (2147483648 - (nptr[i] - '0')) / 10)
// 			return (2147483648);
// 		nb = nb * 10 + (nptr[i] - '0');
// 		i++;
// 	}
// 	return (nb * sign);
// }
