/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:31:21 by ade-rese          #+#    #+#             */
/*   Updated: 2024/03/11 15:34:16 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long long	max_num(long long number0, long long number1)
{
	if (number0 > number1)
		return (number0);
	return (number1);
}

static long long	optimal_cost(long long ra, long long rra,
						long long rb, long long rrb)
{
	long long	ra_rb;
	long long	ra_rrb;
	long long	rra_rb;
	long long	rra_rrb;

	ra_rb = max_num(ra, rb);
	ra_rrb = ra + rrb;
	rra_rb = rra + rb;
	rra_rrb = max_num(rra, rrb);
	if (ra_rb <= ra_rrb && ra_rb <= rra_rb && ra_rb <= rra_rrb)
		return (1);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rb && ra_rrb <= rra_rrb)
		return (2);
	else if (rra_rb <= ra_rb && rra_rb <= ra_rrb && rra_rb <= rra_rrb)
		return (3);
	else
		return (4);
}

static long long	cost_finder(t_frst *stack, long long number)
{
	long long	ra;
	long long	rb;
	long long	rra;
	long long	rrb;
	long long	opti;

	ra = cost_ra(stack, number);
	rb = cost_rb(stack, number);
	rra = cost_rra(stack, number);
	rrb = cost_rrb(stack, number);
	opti = optimal_cost(ra, rra, rb, rrb);
	if (opti == 1)
		return (max_num(ra, rb));
	else if (opti == 2)
		return (ra + rrb);
	else if (opti == 3)
		return (rra + rb);
	else
		return (max_num(rra, rrb));
}

static void	operations(t_frst *stack, long long number)
{
	long long	ra;
	long long	rb;
	long long	rra;
	long long	rrb;
	long long	opti;

	ra = cost_ra(stack, number);
	rb = cost_rb(stack, number);
	rra = cost_rra(stack, number);
	rrb = cost_rrb(stack, number);
	opti = optimal_cost(ra, rra, rb, rrb);
	if (opti == 1)
		ra_rb(stack, ra, rb);
	else if (opti == 2)
		ra_rrb(stack, ra, rrb);
	else if (opti == 3)
		rra_rb(stack, rra, rb);
	else
		rra_rrb(stack, rra, rrb);
}

void	cost(t_frst *stack)
{
	long long	*cost;
	long long	i;
	long long	min_pos;

	while (stack->size_b != 0)
	{
		min_pos = 0;
		cost = malloc(sizeof(long long) * stack->size_b);
		if (!cost)
			return (error_free(stack));
		i = 0;
		while (i < stack->size_b)
		{
			cost[i] = cost_finder(stack, partition_helper((*stack->b), i)->nbr);
			if (cost[i] < cost[min_pos])
				min_pos = i;
			i++;
		}
		operations(stack, partition_helper((*stack->b), min_pos)->nbr);
		free(cost);
	}
	ending(stack);
}
