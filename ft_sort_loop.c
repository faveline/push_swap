/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:23:36 by faveline          #+#    #+#             */
/*   Updated: 2023/11/19 15:56:13 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_sort_part(t_stack *stack, t_med *median, int i, int *cpt)
{
	if (stack->a[0] >= median->med_sup_prev && stack->a[0] <= median->med_sup)
	{
		cpt++;
		pb(stack);
	}
	else if (stack->a[0] <= median->med_inf_prev
		&& stack->a[0] >= median->med_inf)
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
	return (i);
}

int	ft_if_sort(t_stack *stack, int size, t_max *flag)
{
	if (stack->b[0] == flag->max && flag->flag2 == 0)
	{
		flag->flag = 0;
		pa(stack);
		sa(stack);
	}
	else if (stack->b[0] == flag->max)
	{
		flag->flag = 0;
		pa(stack);
	}
	else if (stack->b[0] == flag->max_m && flag->flag2 == 1)
	{
		size--;
		flag->flag = ft_where_max(stack->b, size, stack->size_b);
		flag->flag2 = 0;
		pa(stack);
	}
	else if (flag->flag == 1)
		rrb(stack);
	else
		rb(stack);
	return (size);
}

t_max	ft_ini_flag(t_stack *stack, int size, int preci)
{
	t_max	flag_i;

	flag_i.flag2 = 1;
	flag_i.max = ft_max(stack->b, stack->size_b);
	flag_i.max_m = ft_max_moins_un(stack->b, flag_i.max, stack->size_b);
	flag_i.flag = ft_max_or_max_m(stack, flag_i.max_m, size, preci);
	return (flag_i);
}
