/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:47:25 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 17:26:44 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_creat_stack(int size, char *argv[], t_stack *stack)
{
	int	i;

	stack->a = (int *)malloc(size * sizeof(int));
	if (stack->a == NULL)
		return (-1);
	stack->b = (int *)malloc(size * sizeof(int));
	if (stack->b == NULL)
		return (-2);
	i = 1;
	while (i < size)
	{
		stack->a[i - 1] = ft_atoi(argv[i]);
		stack->b[i - 1] = 0;
		i++;
	}
	stack->size_a = size - 1;
	stack->size_b = 0;
	stack->size = size - 1;
	return (1);
}
