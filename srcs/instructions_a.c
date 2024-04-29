/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:17:44 by abutet            #+#    #+#             */
/*   Updated: 2024/04/18 14:01:40 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_frst *stack, int boole)
{
	t_stack	*tmp;

	if (stack->size_a < 2)
		return ;
	tmp = *stack->a;
	*stack->a = (*stack->a)->next;
	tmp->next = (*stack->a)->next;
	(*stack->a)->next = tmp;
	if (boole)
		write(1, "sa\n", 3);
}

void	ft_pa(t_frst *stack, int boole)
{
	t_stack	*tmp;

	if (stack->size_b < 1)
		return ;
	tmp = *stack->a;
	*stack->a = *stack->b;
	*stack->b = (*stack->b)->next;
	(*stack->a)->next = tmp;
	stack->size_a += 1;
	stack->size_b -= 1;
	if (boole)
		write(1, "pa\n", 3);
}

void	ft_ra(t_frst *stack, int boole)
{
	t_stack		*tmp;

	if (stack->size_a < 2)
		return ;
	tmp = *stack->a;
	*stack->a = ft_lstlast(*stack->a);
	(*stack->a)->next = tmp;
	*stack->a = tmp->next;
	tmp->next = NULL;
	if (boole)
		write(1, "ra\n", 3);
}

void	ft_rra(t_frst *stack, int boole)
{
	t_stack		*tmp;
	long long	imax;

	if (stack->size_a < 2)
		return ;
	imax = 0;
	tmp = *stack->a;
	while ((*stack->a)->next)
	{
		imax++;
		*stack->a = (*stack->a)->next;
	}
	(*stack->a)->next = tmp;
	while (imax-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (boole)
		write(1, "rra\n", 4);
}
