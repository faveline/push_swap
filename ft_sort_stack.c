/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:54 by faveline          #+#    #+#             */
/*   Updated: 2023/11/15 16:25:49 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_stack_sort(int *b, int size)
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

static int	ft_min(int *a)
{
	int	i;
	int	min;

	i = 1;
	min = a[0];
	while (a[i])
	{
		if (min > a[i])
			min = a[i];
		i++;
	}
	return (min);
}

static int	ft_where_min(int *a, int size)
{
	int	i;
	int	min_i;
	int	min;

	i = 1;
	min = a[0];
	min_i = 0;
	while (a[i])
	{
		if (min > a[i])
		{
			min_i = i;
			min = a[i];
		}
		i++;
	}
	if (min_i > size / 2)
		return (1);
	else
		return (-1);
}
/*
void	ft_sort_stack(t_stack *stack)
{
	int	*a;
	int	*b;
	int	i;
	int	size;

	size = stack->size;
	a = stack->a;
	b = stack->b;
	while (size > 1)
	{
		i = 1;
		while (i < size)
		{
			if (a[1] > a[0])
			{
				sa(stack);
				ra(stack);
			}
			else
			{
				ra(stack);				
			}
			i++;
		}
		size --;
		pb(stack);	
	}
	i = 1;
	while (i < stack->size)
	{
		pa(stack);
		i++;
	}
}
*/
void	ft_sort_stack(t_stack *stack)
{
	int	*a;
	int	i;
	int	size;
	int	min;
	int	flag;

	size = stack->size;
	a = stack->a;
	while (size > 1 && ft_is_stack_sort(a, size) < 0)
	{
		flag = ft_where_min(a, size);
		i = 1;
		min = ft_min(a);
		while (flag != 0)
		{
			if (a[0] == min)
			{
				flag = 0;
				pb(stack);
			}
			else
			{
				if (flag == 1)
					rra(stack);
				else
					ra(stack);
			}
			i++;
		}
		size --;
	}
	i = size;
	while (i < (int)stack->size)
	{
		pa(stack);
		i++;
	}
}
















