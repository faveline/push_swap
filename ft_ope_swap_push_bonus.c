/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_swap_push_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:51:29 by faveline          #+#    #+#             */
/*   Updated: 2023/11/29 12:54:21 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_b(t_stack *stack)
{
	int	cpy;

	cpy = stack->a[1];
	stack->a[1] = stack->a[0];
	stack->a[0] = cpy;
}

void	sb_b(t_stack *stack)
{
	int	cpy;

	cpy = stack->b[1];
	stack->b[1] = stack->b[0];
	stack->b[0] = cpy;
}

void	ss_b(t_stack *stack)
{
	int	cpy;
	int	cpy2;

	cpy = stack->a[1];
	stack->a[1] = stack->a[0];
	stack->a[0] = cpy;
	cpy2 = stack->b[1];
	stack->b[1] = stack->b[0];
	stack->b[0] = cpy2;
}

void	pa_b(t_stack *stack)
{
	int	i;
	int	cpy;
	int	cpy2;

	if (stack->size_b == 0)
		return ;
	i = 0;
	cpy = stack->a[0];
	stack->size_a++;
	stack->size_b--;
	while (++i < stack->size_a + 1)
	{
		cpy2 = stack->a[i];
		stack->a[i] = cpy;
		cpy = cpy2;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = 0;
}

void	pb_b(t_stack *stack)
{
	int	i;
	int	cpy;
	int	cpy2;

	if (stack->size_a == 0)
		return ;
	i = 0;
	cpy = stack->b[0];
	stack->size_a--;
	stack->size_b++;
	while (++i < stack->size_b + 1)
	{
		cpy2 = stack->b[i];
		stack->b[i] = cpy;
		cpy = cpy2;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = 0;
}
