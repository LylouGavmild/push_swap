/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:31:28 by ade-rese          #+#    #+#             */
/*   Updated: 2024/03/11 15:33:54 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stackcp(t_stack *stack)
{
	t_stack	*cp;
	t_stack	*tmp;

	cp = ft_lstnew(stack->nbr);
	tmp = stack->next;
	while (tmp)
	{
		ft_lstadd_back(&cp, ft_lstnew(tmp->nbr));
		tmp = tmp->next;
	}
	return (cp);
}

long long	median_finder(t_frst *stack)
{
	t_stack		*cp;
	t_stack		*tmp;
	long long	median_calc;
	long long	median_in_stack;
	long long	rtn;

	median_in_stack = 0;
	cp = stackcp(*stack->a);
	tmp = cp;
	quicksort(tmp, 0, stack->size_a - 1);
	median_calc = (stack->size_a / 2);
	while (median_in_stack < median_calc)
	{
		tmp = tmp->next;
		median_in_stack++;
	}
	rtn = tmp->nbr;
	ft_lstclear(&cp);
	free(cp);
	return (rtn);
}

void	sort_a(t_frst *stack)
{
	if (stack->size_a == 1)
		return ;
	else if (stack->size_a == 2 && (*stack->a)->nbr < (*stack->a)->next->nbr)
		return ;
	else if (stack->size_a == 2 && (*stack->a)->nbr > (*stack->a)->next->nbr)
		ft_ra(stack, 1);
	else
	{
		if ((*stack->a)->nbr > (*stack->a)->next->nbr
			&& (*stack->a)->nbr > (*stack->a)->next->next->nbr)
			ft_ra(stack, 1);
		else if ((*stack->a)->next->nbr > (*stack->a)->nbr
			&& (*stack->a)->next->nbr > (*stack->a)->next->next->nbr)
			ft_rra(stack, 1);
		if ((*stack->a)->nbr > (*stack->a)->next->nbr)
			ft_sa(stack, 1);
	}
}

void	median(t_frst *stack)
{
	long long	median;
	long long	i;

	median = 0;
	while (stack->size_a > 3)
	{
		median = median_finder(stack);
		i = 0;
		while (i < stack->size_a)
		{
			if ((*stack->a)->nbr < median)
				ft_pb(stack, 1);
			else
			{
				i++;
				ft_ra(stack, 1);
			}
		}
	}
	sort_a(stack);
}
