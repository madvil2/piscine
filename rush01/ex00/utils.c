/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:00:22 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/08 18:06:22 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *result[4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ft_putchar(result[r][c] + '0');
			if (c != 3)
				ft_putchar(' ');
			c++;
		}
		r++;
		ft_putchar('\n');
	}
}

void	create_comb(int arr[24][4])
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (i < 96)
	{
		arr[row][col] = COMBINATIONS[i] - '0';
		col++;
		if (col == 4)
		{
			col = 0;
			row++;
		}
		i++;
	}
}

void	get_input(char *av, int arr[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '4')
		{
			arr[j++] = av[i++] - '0';
		}
		else
			i++;
	}
}
