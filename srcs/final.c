/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:39:28 by ade-rese          #+#    #+#             */
/*   Updated: 2024/03/11 15:34:18 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ending(t_frst *stack)
{
	long long	min;
	long long	pos;
	long long	i;

	min = min_a(stack);
	pos = 0;
	while (partition_helper(*stack->a, pos)->nbr != min)
		pos++;
	i = 0;
	if (pos < stack->size_a - pos)
	{
		while (i < pos)
		{
			ft_ra(stack, 1);
			i++;
		}
		return ;
	}
	while (i < stack->size_a - pos)
	{
		ft_rra(stack, 1);
		i++;
	}
}
