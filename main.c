/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:02:53 by faveline          #+#    #+#             */
/*   Updated: 2023/11/17 19:17:39 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	if (ft_error_push_swap(argc, argv, &stack) == 1)
		return (1);
	if (ft_is_it_sorted(&stack) == 1)
		return (ft_delete(&stack), 0);
	if (stack.size > 100)
		ft_sort_stack(&stack, 8, 2, stack.size);
	else if (stack.size > 5)
		ft_sort_stack(&stack, 4, 2, stack.size);
	else if (stack.size >= 2)
		ft_if_five(&stack);
	ft_delete(&stack);
	return (0);
}
