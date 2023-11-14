/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:46:30 by faveline          #+#    #+#             */
/*   Updated: 2023/11/14 16:20:53 by faveline         ###   ########.fr       */
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
	while (stack->a[i])
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
	while (stack->b[i])
	{
		cpy2 = stack->b[i];
		stack->b[i] = cpy;
		cpy = cpy2;
		i++;
	}
	stack->b[0] = cpy;
	ft_printf("rrb\n");
}

static void	rrr_util(int *stack)
{
	int	i;
	int	cpy;
	int	cpy2;

	i = 1;
	cpy = stack[0];
	while (stack[i])
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
	rrr_util(stack->a);
	rrr_util(stack->b);
	ft_printf("rrr\n");
}
