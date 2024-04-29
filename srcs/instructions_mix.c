/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_mix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:17:56 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:26:44 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ss(t_frst *stack, int boole)
{
	if (stack->size_a < 2 || stack->size_b < 2)
		return ;
	ft_sa(stack, 0);
	ft_sb(stack, 0);
	if (boole)
		write(1, "ss\n", 3);
}

void	ft_rr(t_frst *stack, int boole)
{
	if (stack->size_a < 2 || stack->size_b < 2)
		return ;
	ft_ra(stack, 0);
	ft_rb(stack, 0);
	if (boole)
		write(1, "rr\n", 3);
}

void	ft_rrr(t_frst *stack, int boole)
{
	if (stack->size_a < 2 || stack->size_b < 2)
		return ;
	ft_rra(stack, 0);
	ft_rrb(stack, 0);
	if (boole)
		write(1, "rrr\n", 4);
}
