/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:22:11 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 17:29:39 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	size_a;
	int	*b;
	int	size_b;
	int	*sorted;
	int	size;
}		t_stack;

typedef struct s_med
{
	int	med;
	int	med_inf;
	int	med_sup;
	int	med_inf_prev;
	int	med_sup_prev;
}		t_med;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
int		ft_creat_stack(int size, char *argv[], t_stack *stack);
int		ft_check_stack(int size, char *argv[]);
void	ft_printf_a_b(t_stack *stack);
void	ft_delete(t_stack *stack);
void	ft_sort_stack(t_stack *stack, int denum, int preci);
int		ft_where_max(int *a, int size, int size_a);
int		ft_creat_sorted(t_stack *stack);
int		ft_max(int *a, int size);
int		ft_max_moins_un(int *a, int max, int size);
t_med	ft_median(t_stack *stack);
void	ft_median_sup(t_stack *stack, int denum, int nbr, t_med *median);
void	ft_median_inf(t_stack *stack, int denum, int nbr, t_med *median);
int		ft_max_or_max_m(t_stack *stack, int max_m, int i, int preci);
int		ft_is_it_sorted(t_stack *stack);
int		ft_error_push_swap(int argc, char *argv[], t_stack *stack);

#endif
