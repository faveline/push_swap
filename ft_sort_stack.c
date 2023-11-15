/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:54 by faveline          #+#    #+#             */
/*   Updated: 2023/11/15 13:01:55 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_b_sort(int *b, int size)
{
	int	i;

	i = 1;
	while (b[i])
	{
		if (b[i] < b[i - 1])
			return (-1);
		i++;
	}
	if (i != size)
		return (-1);
	return (1);
}

void	ft_sort_stack(t_stack *stack, int size)
{
	int	*a;
	int	*b;
	int	i;

	a = stack->a;
	b = stack->b;
	i = 1;
	if (ft_is_b_sort(stack->a, size) < 0)
	{
		while (i < size)
		{
			ft_printf_a_b(stack);
			if (a[1] < a[0])
			{
				pb(stack);
				if (b[1] && b[1] < b[0])
					rr(stack);
				else
					ra(stack);
			}
			else
				pb(stack);
				if (b[1] && b[1] < b[0])
					rr(stack);
			i++;
		}

		pa(stack);
		if (a[0] > a[1])
			ra(stack);
		i = 1;
		while (i < size - 1)
		{
//			ft_printf_a_b(stack);
			if (b[1] && b[1] < b[0])
			{
				sb(stack);
				pa(stack);
				if (a[1] < a[0])
					ra(stack);
			}
			else
				pa(stack);
				if (a[1] < a[0])
					ra(stack);
			i++;
		}
	}
}
