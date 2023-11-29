/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:29:47 by faveline          #+#    #+#             */
/*   Updated: 2023/11/29 12:56:54 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	ft_checker_stack(t_stack *stack)
{
	int	save;
	int	i;

	if (stack->size_b != 0)
		return (-1);
	save = stack->a[0];
	i = 1;
	while (i < stack->size_a)
	{
		if (save > stack->a[i])
			return (-1);
		save = stack->a[i];
		i++;
	}
	return (1);
}

static void	ft_if_error(void)
{
	ft_printf("ERROR");
}

static int	ft_read_on_stack(t_stack *stack, char *ope)
{
	if (ft_strncmp(ope, "sa\n", 3) == 0)
		sa_b(stack);
	else if (ft_strncmp(ope, "sb\n", 3) == 0)
		sb_b(stack);
	else if (ft_strncmp(ope, "ss\n", 3) == 0)
		ss_b(stack);
	else if (ft_strncmp(ope, "pa\n", 3) == 0)
		pa_b(stack);
	else if (ft_strncmp(ope, "pb\n", 3) == 0)
		pb_b(stack);
	else if (ft_strncmp(ope, "ra\n", 3) == 0)
		ra_b(stack);
	else if (ft_strncmp(ope, "rb\n", 3) == 0)
		rb_b(stack);
	else if (ft_strncmp(ope, "rr\n", 3) == 0)
		rr_b(stack);
	else if (ft_strncmp(ope, "rra\n", 4) == 0)
		rra_b(stack);
	else if (ft_strncmp(ope, "rrb\n", 4) == 0)
		rrb_b(stack);
	else if (ft_strncmp(ope, "rrr\n", 4) == 0)
		rrr_b(stack);
	else
		return (ft_if_error(), -1);
	return (1);
}

void	ft_read_push(t_stack *stack)
{
	char	*next_line;

	next_line = get_next_line(0);
	while (next_line)
	{
		if (ft_read_on_stack(stack, next_line) < 0)
			return (free(next_line));
		free(next_line);
		next_line = get_next_line(0);
	}
	if (ft_checker_stack(stack) < 0)
		ft_printf("KO");
	else
		ft_printf("OK");
}
