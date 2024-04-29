/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:18:12 by abutet            #+#    #+#             */
/*   Updated: 2024/04/18 10:52:21 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stack_helper(t_frst *stack)
{
	int	i;

	i = 0;
	(*stack->a) = ft_lstnew(ft_itoem(ft_atocoi(stack->spl[0]), stack));
	if (!*stack->a)
		error_free(stack);
	while (stack->spl[++i])
	{
		ft_lstadd_back(stack->a,
			ft_lstnew(ft_itoem(ft_atocoi(stack->spl[i]), stack)));
		if (!ft_lstlast((*stack->a)))
			error_free(stack);
	}
}

static void	init_stack(t_frst *stack, char **argv)
{
	int	i;

	stack->jstr = ft_strdup(argv[1]);
	if (!stack->jstr)
		error_free(stack);
	i = 1;
	while (argv[++i])
	{
		stack->jstr = ft_strjoin(stack->jstr, argv[i]);
		if (!stack->jstr)
			error_free(stack);
	}
	stack->spl = ft_split(stack->jstr);
	free(stack->jstr);
	stack->jstr = NULL;
	if (!stack->spl)
		error_free(stack);
	init_stack_helper(stack);
	i = 0;
	while (stack->spl[i])
		free(stack->spl[i++]);
	free(stack->spl);
	stack->spl = NULL;
}

static void	micro_main(t_frst *stack, char **argv)
{
	if (!args_check(argv))
	{
		free(stack->a);
		free(stack->b);
		error();
	}
	init_stack(stack, argv);
	if (!check_double(*stack))
		error_free(stack);
}

int	main(int argc, char **argv)
{
	t_frst	stack;

	null_init(&stack);
	stack.a = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack.a)
		return (0);
	stack.b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack.b)
		error_free(&stack);
	if (argc >= 2)
	{
		micro_main(&stack, argv);
		stack.size_a = ft_lst_size(*stack.a);
		stack.size_b = 0;
		if (!check_if_sort(stack))
		{
			median(&stack);
			cost(&stack);
		}
		ft_lstclear(stack.a);
		ft_lstclear(stack.b);
	}
	free(stack.a);
	free(stack.b);
	return (0);
}
