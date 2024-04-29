/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:17:15 by abutet            #+#    #+#             */
/*   Updated: 2024/04/18 14:59:17 by abutet           ###   ########.fr       */
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
