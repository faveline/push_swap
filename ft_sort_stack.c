/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:54 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 17:39:59 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_no_value(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] >= min && stack->a[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_sort_part(t_stack *stack, int size, t_med *median)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (i < size
		&& ft_no_value(stack, median->med_inf, median->med_sup) == 1)
	{
		i = ft_if_sort_part(stack, median, i, &cpt);
		i++;
	}
	return (cpt);
}

static void	ft_min_max(t_stack *stack, int denum)
{
	int		i;
	t_med	median;
	int		cpt;

	i = 1;
	cpt = 0;
	median = ft_median(stack);
	while (i <= denum)
	{
		ft_median_inf(stack, denum, i, &median);
		ft_median_sup(stack, denum, i, &median);
		cpt += ft_sort_part(stack, stack->size - cpt, &median);
		i++;
	}
	while (stack->size_a > 0)
		pb(stack);
}

void	ft_sort_stack(t_stack *stack, int preci_denum, int preci_max, int size)
{
	t_max	flag;

	ft_min_max(stack, preci_denum);
	while (size > 0)
	{
		flag = ft_ini_flag(stack, size, preci_max);
		while (flag.flag != 0)
			size = ft_if_sort(stack, size, &flag);
		size --;
	}
}
