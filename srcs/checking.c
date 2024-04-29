/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:16:41 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:26:08 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_issign(int c)
{
	return (c == 43 || c == 45);
}

int	ft_issign_or_space(int c)
{
	return (c == 43 || c == 45 || (c >= 9 && c <= 13) || c == 32);
}

int	check_double(t_frst stack)
{
	t_stack	*tmp;
	t_stack	*pri;

	pri = *stack.a;
	while (pri)
	{
		tmp = pri->next;
		while (tmp)
		{
			if (pri->nbr == tmp->nbr)
				return (0);
			tmp = tmp->next;
		}
		pri = pri->next;
	}
	return (1);
}

int	check_if_sort(t_frst stack)
{
	t_stack	*tmp;

	tmp = *stack.a;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
