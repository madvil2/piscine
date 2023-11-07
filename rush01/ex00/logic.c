/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:59:18 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/08 18:28:06 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	brute2(int *result[4], int comb[24][4], int clues[16], int r[4])
{
	while (r[3] < 24)
	{
		result[0] = comb[r[0]];
		result[1] = comb[r[1]];
		result[2] = comb[r[2]];
		result[3] = comb[r[3]];
		if (check(result, clues) && unic(result))
		{
			print(result);
			return (0);
		}
		r[3]++;
	}
	return (1);
}

void	brute_force(int *result[4], int comb[24][4], int clues[16])
{
	int	r[4];

	r[0] = 0;
	while (r[0] < 24)
	{
		r[1] = 0;
		while (r[1] < 24)
		{
			r[2] = 0;
			while (r[2] < 24)
			{
				r[3] = 0;
				brute2(result, comb, clues, r);
				r[2]++;
			}
			r[1]++;
		}
		r[0]++;
	}
}

int	check(int *arr[4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (clues[i] != count(arr[0][i], arr[1][i], arr[2][i], arr[3][i]))
			return (0);
		if (clues[i + 4] != count(arr[3][i], arr[2][i], arr[1][i], arr[0][i]))
			return (0);
		if (clues[i + 8] != count(arr[i][0], arr[i][1], arr[i][2], arr[i][3]))
			return (0);
		if (clues[i + 12] != count(arr[i][3], arr[i][2], arr[i][1], arr[i][0]))
			return (0);
		i++;
	}
	return (1);
}

int	count(int a, int b, int c, int d)
{
	int	res;

	res = 1;
	if (b > a)
		res++;
	if (c > b && c > a)
		res++;
	if (d > c && d > b && d > a)
		res++;
	return (res);
}

int	unic(int *result[4])
{
	int	col;
	int	i;
	int	j;

	col = 0;
	while (col < 4)
	{
		i = 0;
		while (i < 4)
		{
			j = i + 1;
			while (j < 4)
			{
				if (result[i][col] == result[j][col])
					return (0);
				j++;
			}
			i++;
		}
		col++;
	}
	return (1);
}
