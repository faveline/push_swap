/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:10:16 by faveline          #+#    #+#             */
/*   Updated: 2023/11/24 11:20:40 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_long(const char *str)
{
	int		i;
	long	atoi;
	int		signe;

	signe = 1;
	atoi = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -1;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		atoi = atoi * 10 + str[i] - 48;
		i++;
	}
	return (atoi * signe);
}

static int	ft_check_duplicate(int *tab, int nbr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tab[j] == nbr)
			return (-3);
		j++;
	}
	return (1);
}

static int	ft_comp_str(char *str1, char *str2)
{
	int	j;

	j = 0;
	while (str1[j])
	{
		if (str1[j] != str2[j])
			return (-1);
		j++;
	}
	return (1);
}

int	ft_check_stack(int argc, char *argv[])
{
	int		i;
	int		nbr;
	char	*check;
	int		*tab_i;

	tab_i = (int *)malloc(argc * sizeof(int));
	if (tab_i == NULL)
		return (-2);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (free(tab_i), -5);
		nbr = ft_atoi(argv[i]);
		if (nbr != ft_atoi_long(argv[i]))
			return (free(tab_i), -4);
		tab_i[i - 1] = nbr;
		if (ft_check_duplicate(tab_i, nbr, i - 1) < 0)
			return (free(tab_i), -3);
		check = ft_itoa(nbr);
		if (ft_comp_str(argv[i], check) < 0)
			return (free(tab_i), free(check), -1);
		free(check);
		i++;
	}
	free(tab_i);
	return (1);
}
