/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:09 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 17:31:01 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->sorted);
}

void	ft_printf_a_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->size_a > i)
			ft_printf("%d\t", stack->a[i]);
		else
			ft_printf(" \t");
		if (stack->size_b > i)
			ft_printf("%d\n", stack->b[i]);
		else
			ft_printf(" \n");
		i++;
	}
	ft_printf("*****************\na\tb\n");
}

int	ft_is_it_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->a[i] != stack->sorted[i])
			return (-1);
		i++;
	}
	return (1);
}

int	ft_error_push_swap(int argc, char *argv[], t_stack *stack)
{
	int	error;

	if (ft_check_stack(argc, argv) < 0)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	error = ft_creat_stack(argc, argv, stack);
	if (error == -1)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	else if (error == -2)
	{
		ft_printf("ERROR\n");
		return (free(stack->a), 1);
	}
	if (ft_creat_sorted(stack) < 0)
	{
		ft_printf("ERROR\n");
		return (free(stack->a), free(stack->b), 1);
	}
	return (0);
}
