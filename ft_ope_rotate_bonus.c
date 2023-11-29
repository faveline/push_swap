/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:39:07 by faveline          #+#    #+#             */
/*   Updated: 2023/11/29 12:55:20 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_stack *stack)
{
	int	i;
	int	cpy;

	cpy = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = cpy;
}

void	rb_b(t_stack *stack)
{
	int	i;
	int	cpy;

	cpy = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = cpy;
}

static void	rr_util(int *stack, int size)
{
	int	i;
	int	cpy;

	cpy = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = cpy;
}

void	rr_b(t_stack *stack)
{
	rr_util(stack->a, stack->size_a);
	rr_util(stack->b, stack->size_b);
}
