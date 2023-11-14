/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:09 by faveline          #+#    #+#             */
/*   Updated: 2023/11/14 17:26:57 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printf_a_b(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (stack->a[i])
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
	ft_printf("***\n");
	i = 0;
	while (stack->b[i])
	{
		ft_printf("%d\n", stack->b[i]);
		i++;
	}
}
