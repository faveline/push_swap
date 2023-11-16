/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:54 by faveline          #+#    #+#             */
/*   Updated: 2023/11/16 14:33:09 by faveline         ###   ########.fr       */
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
/*
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
*/
static int	ft_where_max(int *a, int size)
{
	int	i;
	int	max_i;
	int	max;

	i = 1;
	max = a[0];
	max_i = 0;
	while (a[i])
	{
		if (max < a[i])
		{
			max_i = i;
			max = a[i];
		}
		i++;
	}
	if (max_i >= size / 2)
		return (1);
	else
		return (-1);
}

static int	ft_max_moins_un(int *a, int max)
{
	int	i;
	int	max_m;

	i = 1;
	max_m = a[0];
	while (a[i])
	{
		if (max_m < a[i] && a[i] != max)
			max_m = a[i];
		i++;
	}
	return (max_m);
}

static int	ft_max(int *a)
{
	int	i;
	int	max;

	i = 1;
	max = a[0];
	while (a[i])
	{
		if (max < a[i])
			max = a[i];
		i++;
	}
	return (max);
}

static int	ft_mid(int *a)
{
	unsigned int	i;
	unsigned int	mid;

	mid = 0;
	i = 0;
	while (a[i])
	{
		mid += a[i];
		i++;
	}
	mid /= i;
	return (mid);
}

static int	ft_no_value(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (stack->a[i])
	{
		if (stack->a[i] <= min || stack->a[i] >= max)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_sort_part(t_stack *stack, int min, int max, unsigned int size, unsigned int denum)
{
	unsigned int	i;
	int				cpt;

	i = 0;
	cpt = 0;
	while (i < size && stack->a[0] && ft_no_value(stack, min, max) == 1)
	{
		if (stack->a[0] >= max)
		{
			cpt++;
			pb(stack);
		}
		else if (stack->a[0] <= min)
		{	
			cpt++;
			pb(stack);
			if (stack->a[0] >= min && stack->a[0] <= max)
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
		if ((unsigned int)cpt > stack->size / denum * 11 / 10)
			return (cpt);
	}
	return (cpt);
}

static void	ft_min_max(t_stack *stack, unsigned int denum)
{
	unsigned int	i;
	int				mid;
	unsigned int	cpt;

	i = 1;
	cpt = 0;
	while (i <= denum)
	{
		if (stack->a[0])
			mid = ft_mid(stack->a); 
		cpt += ft_sort_part(stack, mid * i / denum, mid * (2 * denum - i) / denum, stack->size - cpt, denum);
		i++;
	}
	if (stack->a[0])
		pb(stack);
	/*while (i < stack->size && stack->a[0])
	{
		if (stack->a[0] > mid)
			pb(stack);
		else
		{		
			pb(stack);
			rb(stack);
		}
		i++;
	}*/
//	while (stack->b[0])
//		pa(stack);
		
}

void	ft_sort_stack(t_stack *stack)
{
//	int				*a;
//	unsigned int	i;
	int				size;
	int				max;
	int				flag;
	int				*b;
	int				flag2;
	int				max_m;

	size = stack->size;
//	a = stack->a;
	b = stack->b;
	ft_min_max(stack, 7);
	while (size > 0 && ft_is_stack_sort(b, (int)stack->size) < 0)
	{
		flag2 = 1;
		flag = ft_where_max(b, size);
		max = ft_max(b);
		max_m = ft_max_moins_un(b, max);
		while (flag != 0)
		{
			if (b[0] == max && flag2 == 0)
			{
				flag = 0;
				pa(stack);
				sa(stack);
			}
			else if (b[0] == max)
			{
				flag = 0;
				pa(stack);			
			}
			else if (b[0] == max_m && flag2 == 1)
			{
				size--;
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
//	i = (unsigned int)size;
/*	while (i < stack->size)
	{
		pa(stack);
		i++;
	}*/
}
















