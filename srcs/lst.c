/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-rese <ade-rese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:36:08 by ade-rese          #+#    #+#             */
/*   Updated: 2024/02/15 15:34:01 by ade-rese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	null_init(t_frst *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->jstr = NULL;
	stack->spl = NULL;
}

int	ft_lst_size(t_stack *stack)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*ft_lstnew(long long nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->nbr = nbr;
	new->next = 0;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*addback;

	addback = ft_lstlast(*lst);
	addback->next = new;
}
