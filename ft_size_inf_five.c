/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_inf_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:13:22 by faveline          #+#    #+#             */
/*   Updated: 2023/11/24 09:55:04 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min(t_stack *stack)
{
	int	i;
	int	i_min;
	int	min;

	i = 0;
	i_min = 0;
	min = stack->a[0];
	while (i < stack->size_a)
	{
		if (min > stack->a[i])
		{
			i_min = i;
			min = stack->a[i];
		}
		i++;
	}
	return (i_min);
}

void	ft_if_five(t_stack *stack)
{	
	int	i_min;

	while (stack->size_a > 2)
	{
		i_min = ft_min(stack);
		if (i_min <= 2)
		{
			while (i_min > 0)
			{
				ra(stack);
				i_min--;
			}
		}
		else
		{
			rra(stack);
			if (stack->size_a == 5 && i_min == 3)
				rra(stack);
		}
		pb(stack);
	}
	if (stack->a[0] > stack->a[1])
		sa(stack);
	while (stack->size_b != 0)
		pa(stack);
}

void	ft_if_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
	if (ft_is_it_sorted(stack) == 1)
		return ;
	rra(stack);
	if (ft_is_it_sorted(stack) == 1)
		return ;
	if (stack->a[0] < stack->a[2])
		sa(stack);
}
