/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:24:24 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:24:24 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 && *s2) != '\0')
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	op_input(t_frst *stack, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(stack, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(stack, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(stack, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(stack, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(stack, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(stack, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(stack, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(stack, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(stack, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		ft_rr(stack, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(stack, 0);
	else
		return (0);
	return (1);
}

void	input(t_frst *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{	
		if (op_input(stack, str) == 0)
		{
			get_next_line(-1);
			free(str);
			error_free(stack);
		}
		free(str);
		str = get_next_line(0);
	}
}
