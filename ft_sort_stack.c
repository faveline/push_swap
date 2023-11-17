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
	while (i < size && ft_no_value(stack, median->med_inf, median->med_sup) == 1)
	{
		if (stack->a[0] >= median->med_sup_prev && stack->a[0] <= median->med_sup)
		{
			cpt++;
			pb(stack);
		}
		else if (stack->a[0] <= median->med_inf_prev && stack->a[0] >= median->med_inf)
		{	
			cpt++;
			pb(stack);
			if (stack->a[0] <= median->med_inf || stack->a[0] >= median->med_sup)
			{
				i++;
				rr(stack);
			}
			else
				rb(stack);
		}
		else
			ra(stack);
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

void	ft_sort_stack(t_stack *stack, int preci_denum, int preci_max)
{
	int				size;
	int				max;
	int				flag;
	int				flag2;
	int				max_m;

	size = stack->size;
	ft_min_max(stack, preci_denum);
	while (size > 0)
	{
		flag2 = 1;
		max = ft_max(stack->b, stack->size_b);
		max_m = ft_max_moins_un(stack->b, max, stack->size_b);
		flag = ft_max_or_max_m(stack, max_m, size, preci_max);
		while (flag != 0)
		{
			if (stack->b[0] == max && flag2 == 0)
			{
				flag = 0;
				pa(stack);
				sa(stack);
			}
			else if (stack->b[0] == max)
			{
				flag = 0;
				pa(stack);
			}
			else if (stack->b[0] == max_m && flag2 == 1)
			{
				size--;
				flag = ft_where_max(stack->b, size, stack->size_b);
				flag2 = 0;
				pa(stack);
			}
			else
			{
				if (flag == 1)
					rrb(stack);
				else
					rb(stack);
			}
		}
		size --;
	}
}
