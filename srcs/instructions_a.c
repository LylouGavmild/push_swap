/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-rese <ade-rese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:09:52 by ade-rese          #+#    #+#             */
/*   Updated: 2024/03/11 11:26:17 by ade-rese         ###   ########.fr       */
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
