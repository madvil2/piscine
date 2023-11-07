/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:18:27 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 21:26:41 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	print_error(void)
{
	write(1, "map error\n", 10);
	return (0);
}

int	ft_strlen(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res++;
	return (res);
}

int	nullification(char *str, int size)
{
	while (size > 0)
	{
		str[size - 1] = 0;
		size--;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(char **map, t_bsq data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.y)
	{
		j = 0;
		while (j < data.x)
		{
			if (j >= data.y_start && j < data.y_start + data.max
				&& i >= data.x_start && i < data.x_start + data.max)
				ft_putchar(data.charset[2]);
			else
				ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	data.x_start = 0;
	data.y_start = 0;
}
