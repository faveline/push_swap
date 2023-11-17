/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:46:30 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 17:33:32 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	i;
	int	cpy;
	int	cpy2;

	i = 1;
	cpy = stack->a[0];
	while (i < stack->size_a)
	{
		cpy2 = stack->a[i];
		stack->a[i] = cpy;
		cpy = cpy2;
		i++;
	}
	stack->a[0] = cpy;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	i;
	int	cpy;
	int	cpy2;

	i = 1;
	cpy = stack->b[0];
	while (i < stack->size_b)
	{
		cpy2 = stack->b[i];
		stack->b[i] = cpy;
		cpy = cpy2;
		i++;
	}
	stack->b[0] = cpy;
	ft_printf("rrb\n");
}

static void	rrr_util(int *stack, int size)
{
	int	i;
	int	cpy;
	int	cpy2;

	i = 1;
	cpy = stack[0];
	while (i < size)
	{
		cpy2 = stack[i];
		stack[i] = cpy;
		cpy = cpy2;
		i++;
	}
	stack[0] = cpy;
}

void	rrr(t_stack *stack)
{
	rrr_util(stack->a, stack->size_a);
	rrr_util(stack->b, stack->size_b);
	ft_printf("rrr\n");
}
