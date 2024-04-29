/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:12:46 by abutet            #+#    #+#             */
/*   Updated: 2024/04/18 15:00:03 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long long		nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_frst
{
	t_stack		**a;
	t_stack		**b;
	char		*jstr;
	char		**spl;
	long long	size_a;
	long long	size_b;
}	t_frst;

int			ft_issign(int c);
int			ft_isdigit(int c);
int			is_whitespace(char c);
int			args_check(char **argv);
int			ft_issign_or_space(int c);
int			check_double(t_frst stack);
int			check_if_sort(t_frst stack);
int			ft_lst_size(t_stack *stack);
t_stack		*stackcp(t_stack *stack);
t_stack		*ft_lstnew(long long nbr);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*partition_helper(t_stack *stack, long long lrp);
long long	min_a(t_frst *stack);
long long	ft_strlen(const char *s);
long long	ft_atocoi(const char *nptr);
long long	median_finder(t_frst *stack);
long long	ft_itoem(long long i, t_frst *a);
long long	cost_ra(t_frst *stack, long long number);
long long	cost_rb(t_frst *stack, long long number);
long long	cost_rra(t_frst *stack, long long number);
long long	cost_rrb(t_frst *stack, long long number);
long long	ft_strlcpy(char *dst, char *src, long long size);
void		error(void);
void		cost(t_frst *stack);
void		ending(t_frst *stack);
void		sort_a(t_frst *stack);
void		median(t_frst *stack);
void		null_init(t_frst *stack);
void		error_free(t_frst *stack);
void		ft_lstclear(t_stack **lst);
void		ft_sa(t_frst *stack, int boole);
void		ft_sb(t_frst *stack, int boole);
void		ft_ra(t_frst *stack, int boole);
void		ft_rb(t_frst *stack, int boole);
void		ft_rra(t_frst *stack, int boole);
void		ft_rrb(t_frst *stack, int boole);
void		ft_pa(t_frst *stack, int boole);
void		ft_pb(t_frst *stack, int boole);
void		ft_ss(t_frst *stack, int boole);
void		ft_rr(t_frst *stack, int boole);
void		ft_rrr(t_frst *stack, int boole);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		*ft_memcpy(void *dest, void *src, long long n);
void		ra_rb(t_frst *stack, long long cost_ra, long long cost_rb);
void		rra_rb(t_frst *stack, long long cost_rra, long long cost_rb);
void		ra_rrb(t_frst *stack, long long cost_ra, long long cost_rrb);
void		rra_rrb(t_frst *stack, long long cost_rra, long long cost_rrb);
void		quicksort(t_stack *stack, long long left_pos, long long right_pos);
char		*ft_strdup(char *s);
char		**ft_split(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, long long len);

#endif
