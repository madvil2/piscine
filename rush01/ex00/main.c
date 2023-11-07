/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:00:58 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/08 18:27:48 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_input(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!((i % 2 == 0 && av[i] >= '1' && av[i] <= '4')
				|| (i % 2 == 1 && av[i] == ' ')))
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	int	comb[24][4];
	int	*result[4];
	int	clues[16];

	if (ac == 2)
	{
		if (check_input(av[1]) == 1)
		{
			get_input(av[1], clues);
			create_comb(comb);
			brute_force(result, comb, clues);
		}
		else
		{
			write(1, "Error\n", 7);
			return (1);
		}
	}
	else
		write(1, "Error\n", 7);
	return (0);
}
