/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:17:59 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 21:26:41 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	return (c);
}

void	bsq_solve(char **map, int **tab, t_bsq *data)
{
	int	i;
	int	j;

	i = data->y - 1;
	while (i >= 0)
	{
		j = data->x - 1;
		while (j >= 0)
		{
			if (map[i][j] == data->charset[1])
				tab[i][j] = 0;
			else
				tab[i][j] = min(tab[i + 1][j], tab[i][j + 1], tab[i + 1][j + 1])
					+ 1;
			if (data->max <= tab[i][j])
			{
				data->max = tab[i][j];
				data->x_start = i;
				data->y_start = j;
			}
			j--;
		}
		i--;
	}
}
