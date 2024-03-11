/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-rese <ade-rese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:48:25 by ade-rese          #+#    #+#             */
/*   Updated: 2024/03/05 15:33:58 by ade-rese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(t_stack *a, t_stack *b)
{
	long long	c;

	c = a->nbr;
	a->nbr = b->nbr;
	b->nbr = c;
}

t_stack	*partition_helper(t_stack *stack, long long lrp)
{
	t_stack		*tmp;
	long long	i;

	i = 0;
	tmp = stack;
	while (i < lrp)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

static long long	partition(t_stack *stack, long long lp, long long rp)
{
	t_stack		*tmp;
	long long	pivot;
	long long	i;
	long long	j;

	pivot = partition_helper(stack, rp)->nbr;
	tmp = partition_helper(stack, lp);
	stack = tmp;
	i = lp;
	j = lp;
	while (j < rp)
	{
		if (tmp->nbr <= pivot)
		{
			ft_swap(stack, tmp);
			stack = stack->next;
			i++;
		}
		tmp = tmp->next;
		j++;
	}
	ft_swap(stack, tmp);
	return (i);
}

void	quicksort(t_stack *stack, long long left_pos, long long right_pos)
{
	long long	pivot;

	if (left_pos < right_pos)
	{
		pivot = partition(stack, left_pos, right_pos);
		quicksort(stack, left_pos, pivot - 1);
		quicksort(stack, pivot + 1, right_pos);
	}
}
