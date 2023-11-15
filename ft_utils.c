/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:09 by faveline          #+#    #+#             */
/*   Updated: 2023/11/15 12:19:53 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
}

void	ft_printf_a_b(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->a[i])
			ft_printf("%d\t", stack->a[i]);
		else
			ft_printf(" \t");
		if (stack->b[i])
			ft_printf("%d\n", stack->b[i]);
		else
			ft_printf(" \n");
		i++;
	}
	ft_printf("*****************\na\tb\n");
}
