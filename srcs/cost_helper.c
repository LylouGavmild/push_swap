/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:16:48 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:26:12 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	min_a(t_frst *stack)
{
	long long	i;
	long long	min;
	t_stack		*tmp;

	i = 1;
	min = (*stack->a)->nbr;
	tmp = *stack->a;
	while (i < stack->size_a)
	{
		tmp = tmp->next;
		if (tmp->nbr < min)
			min = tmp->nbr;
		i++;
	}
	return (min);
}

long long	cost_ra(t_frst *stack, long long number)
{
	const long long	min = min_a(stack);
	long long		i;
	t_stack			*tmp;
	t_stack			*tmp2;

	tmp = *stack->a;
	i = 0;
	if (min > number)
		while (partition_helper((*stack->a), i)->nbr != min)
			i++;
	else
	{
		tmp2 = partition_helper((*stack->a), stack->size_a - 1);
		while (tmp->nbr < number || number < tmp2->nbr)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
			i++;
			if (!tmp2)
				tmp2 = *stack->a;
		}
	}
	return (i);
}

long long	cost_rra(t_frst *stack, long long number)
{
	long long	min;
	long long	ptr1;
	long long	ptr2;

	ptr1 = stack->size_a - 1;
	min = min_a(stack);
	if (min > number)
	{
		while (partition_helper((*stack->a), ptr1)->nbr != min)
			ptr1--;
		ptr1--;
	}
	else
	{
		ptr2 = 0;
		while (partition_helper((*stack->a), ptr2)->nbr < number
			|| number < partition_helper((*stack->a), ptr1)->nbr)
		{
			ptr1--;
			ptr2--;
			if (ptr2 == -1)
				ptr2 = stack->size_a - 1;
		}
	}
	return (stack->size_a - 1 - ptr1);
}

long long	cost_rb(t_frst *stack, long long number)
{
	t_stack		*tmp;
	long long	i;

	tmp = *stack->b;
	i = 0;
	while (tmp->nbr != number)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

long long	cost_rrb(t_frst *stack, long long number)
{
	long long	ptr;

	ptr = stack->size_b - 1;
	while (partition_helper((*stack->b), ptr)->nbr != number)
		ptr--;
	return (stack->size_b - ptr);
}
