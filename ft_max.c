/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:30:20 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 17:35:24 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_flag_max(int i_max, int i_max_m, int size, int preci)
{
	int	flag;

	flag = 0;
	if (i_max >= size / 2)
	{
		flag += 1;
		i_max = size - i_max;
	}
	if (i_max_m >= size / 2)
	{
		flag += 10;
		i_max_m = size - i_max_m;
	}
	if (flag == 0)
		return (-1);
	else if (i_max >= i_max_m + preci && flag == 1)
		return (-1);
	else if (i_max >= i_max_m + preci && (flag == 10 || flag == 11))
		return (1);
	else if (i_max <= i_max_m + preci && (flag == 1 || flag == 11))
		return (1);
	else if (i_max <= i_max_m + preci && flag == 10)
		return (-1);
	return (-1);
}

int	ft_max_or_max_m(t_stack *stack, int max_m, int size, int preci)
{
	int	i;
	int	i_max;
	int	i_max_m;
	int	max;

	max = ft_max(stack->b, stack->size_b);
	i = 0;
	while (i < stack->size_b)
	{
		if (stack->b[i] == max)
			i_max = i;
		if (stack->b[i] == max_m)
			i_max_m = i;
		i++;
	}
	return (ft_flag_max(i_max, i_max_m, size, preci));
}

int	ft_where_max(int *a, int size, int size_a)
{
	int	i;
	int	max_i;
	int	max;

	i = 1;
	max = a[0];
	max_i = 0;
	while (i < size_a)
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

int	ft_max_moins_un(int *a, int max, int size)
{
	int	i;
	int	max_m;

	i = 1;
	max_m = a[0];
	while (i < size)
	{
		if (max_m < a[i] && a[i] != max)
			max_m = a[i];
		i++;
	}
	return (max_m);
}

int	ft_max(int *a, int size)
{
	int	i;
	int	max;

	i = 1;
	max = a[0];
	while (i < size)
	{
		if (max < a[i])
			max = a[i];
		i++;
	}
	return (max);
}
