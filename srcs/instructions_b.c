/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:17:50 by abutet            #+#    #+#             */
/*   Updated: 2024/04/18 14:02:37 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sb(t_frst *stack, int boole)
{
	t_stack	*tmp;

	if (stack->size_b < 2)
		return ;
	tmp = *stack->b;
	*stack->b = (*stack->b)->next;
	tmp->next = (*stack->b)->next;
	(*stack->b)->next = tmp;
	if (boole)
		write(1, "sb\n", 3);
}

void	ft_pb(t_frst *stack, int boole)
{
	t_stack	*tmp;

	if (stack->size_a < 1)
		return ;
	if (stack->size_b == 0)
		tmp = NULL;
	else
		tmp = *stack->b;
	*stack->b = *stack->a;
	*stack->a = (*stack->a)->next;
	(*stack->b)->next = tmp;
	stack->size_b += 1;
	stack->size_a -= 1;
	if (boole)
		write(1, "pb\n", 3);
}

void	ft_rb(t_frst *stack, int boole)
{
	t_stack	*tmp;

	if (stack->size_b < 2)
		return ;
	tmp = *stack->b;
	*stack->b = ft_lstlast(*stack->b);
	(*stack->b)->next = tmp;
	*stack->b = tmp->next;
	tmp->next = NULL;
	if (boole)
		write(1, "rb\n", 3);
}

void	ft_rrb(t_frst *stack, int boole)
{
	t_stack		*tmp;
	long long	imax;

	if (stack->size_b < 2)
		return ;
	imax = 0;
	tmp = *stack->b;
	while ((*stack->b)->next)
	{
		imax++;
		*stack->b = (*stack->b)->next;
	}
	(*stack->b)->next = tmp;
	while (imax-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (boole)
		write(1, "rrb\n", 4);
}
