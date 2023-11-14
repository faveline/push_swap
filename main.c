/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:02:53 by faveline          #+#    #+#             */
/*   Updated: 2023/11/14 16:30:12 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int			stacka[9] = {1, 2, 3, 4, 5};
	int			stackb[9] = {6, 7, 8};
	int			i;
	t_stack		stack;
	stack.a = stacka;
	stack.b = stackb;

	rr(&stack);
	i = 0;
	while (stack.a[i])
	{
		ft_printf("%d\n", stack.a[i]);
		i++;
	}
	ft_printf("test\n");
	i = 0;
	while (stack.b[i])
	{
		ft_printf("%d\n", stack.b[i]);
		i++;
	}
	return (0);

}
