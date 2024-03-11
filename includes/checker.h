/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-rese <ade-rese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:10:34 by ade-rese          #+#    #+#             */
/*   Updated: 2024/03/11 10:10:46 by ade-rese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "push_swap.h"

char	*ft_next(char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_free_string(char *str);
char	*ft_true_strjoin(char *s1, char *s2);
int		ft_is_new_line(char *str);
void	input(t_frst *stack);

#endif
