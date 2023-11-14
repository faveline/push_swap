/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:02:53 by faveline          #+#    #+#             */
/*   Updated: 2023/11/14 18:09:57 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc <= 2)
		return (0);
	if (ft_creat_stack((unsigned int)argc, argv, &stack) < 0)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	ft_printf_a_b(&stack);
	return (0);
}
