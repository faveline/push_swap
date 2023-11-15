/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:47:25 by faveline          #+#    #+#             */
/*   Updated: 2023/11/15 11:48:51 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_creat_stack(unsigned int size, char *argv[], t_stack *stack)
{
	unsigned int	i;

	stack->a = (int *)malloc(size * sizeof(int));
	if (stack->a == NULL)
		return (-1);
	stack->b = (int *)malloc(size * sizeof(int));
	if (stack->b == NULL)
		return (-1);
	i = 1;
	while (i < size)
	{
		stack->a[i - 1] = ft_atoi(argv[i]);
		stack->b[i - 1] = '\0';
		i++;
	}
	stack->a[i - 1] = '\0';
	stack->b[i - 1] = '\0';
	stack->size = size - 1;
	return (1);
}
