/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-rese <ade-rese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:12:07 by ade-rese          #+#    #+#             */
/*   Updated: 2024/03/11 11:39:56 by ade-rese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*clearer;

	if (!lst)
		return ;
	while (*lst)
	{
		clearer = (*lst)->next;
		free(*lst);
		*lst = clearer;
	}
	*lst = NULL;
}

void	error_free(t_frst *stack)
{
	int	i;

	i = 0;
	ft_lstclear(stack->a);
	if (stack->size_b > 0)
		ft_lstclear(stack->b);
	free(stack->a);
	free(stack->b);
	free(stack->jstr);
	if (stack->spl)
	{
		while (stack->spl[i])
			free(stack->spl[i++]);
	}
	free(stack->spl);
	error();
}
