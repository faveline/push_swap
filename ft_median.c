/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:34:11 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 17:37:12 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_med	ft_median(t_stack *stack)
{
	t_med	median;

	median.med = stack->sorted[stack->size / 2 + 1];
	median.med_inf_prev = stack->sorted[stack->size / 2 + 1];
	median.med_sup_prev = stack->sorted[stack->size / 2 + 1];
	median.med_inf = stack->sorted[stack->size / 2 + 1];
	median.med_sup = stack->sorted[stack->size / 2 + 1];
	return (median);
}

void	ft_median_sup(t_stack *stack, int denum, int nbr, t_med *median)
{
	if (median->med_sup_prev == median->med)
		median->med_sup = stack->sorted[stack->size
			* (denum + nbr) / (2 * denum) - 1];
	else
	{
		median->med_sup_prev = median->med_sup;
		median->med_sup = stack->sorted[stack->size
			* (denum + nbr) / (2 * denum) - 1];
	}
}

void	ft_median_inf(t_stack *stack, int denum, int nbr, t_med *median)
{
	if (median->med_inf_prev == median->med)
		median->med_inf = stack->sorted[stack->size
			* (denum - nbr) / (2 * denum)];
	else
	{
		median->med_inf_prev = median->med_inf;
		median->med_inf = stack->sorted[stack->size
			* (denum - nbr) / (2 * denum)];
	}
}

static void	ft_sort_sorted(t_stack *stack, int i, int size)
{
	int	max;
	int	i_max;

	while (size > 1)
	{
		i = 0;
		max = stack->sorted[0];
		i_max = 0;
		while (i < size)
		{
			if (max < stack->sorted[i])
			{
				i_max = i;
				max = stack->sorted[i];
			}
			i++;
		}
		stack->sorted[i_max] = stack->sorted[i - 1];
		stack->sorted[i - 1] = max;
		size--;
	}
}

int	ft_creat_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	stack->sorted = (int *)malloc((stack->size + 1) * sizeof(int));
	if (stack->sorted == NULL)
		return (-1);
	while (i < stack->size + 1)
	{	
		stack->sorted[i - 1] = stack->a[i - 1];
		i++;
	}
	ft_sort_sorted(stack, 0, stack->size);
	return (1);
}
