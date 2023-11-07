/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:13:58 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/15 20:14:07 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	print_hundreds(char a, char b, char c, char **dict)
{
	if (a != '0') // saying the hundreds
	{
		ft_putstr(dict[a - '0']);
		ft_putchar(' ');
		ft_putstr(dict[28]);
		if (b != '0' || c != '0')
			ft_putchar(' ');
	}
	if (b != '0') // saying the tens
	{
		if (b > '1')
		{
			ft_putstr(dict[b - '0' + 18]);
			if (c != '0')
				ft_putchar(' ');
		}
		else
			ft_putstr(dict[c - '0' + 10]);
	}
	if (c != '0' && b != '1') //saying the ones
		ft_putstr(dict[c - '0']);
}

void	print_reminder(char *nb, char **dict, int len, int *i) //printing first one/two digits with suffix
{
	if (len % 3 == 1 && nb[*i] != '0')
		print_hundreds('0', '0', nb[*i], dict);
	else
		print_hundreds('0', nb[*i], nb[*i + 1], dict);
	if (*i < len - 3)
	{
		ft_putchar(' ');
		ft_putstr(dict[(len - 1 - (*i)) / 3 + 28]);
	}
	(*i) += len % 3;
}

void	if_zero(char **dict)
{
	if (!dict)
		return ((void) error_print(2));
	ft_putstr(dict[0]);
	ft_putchar('\n');
	free_arr(dict, 41, 0);
}

void	print(char *nb, char **dict)
{
	int	i;
	int	len;

	len = ft_strlen(nb);
	i = 0;
	if (ft_atoi(nb) == 0 || !dict)
		return (if_zero(dict));
	if (len % 3 != 0 && i == 0)
		print_reminder(nb, dict, len, &i);
	while (i < len)
	{
		if ((nb[i] != '0') || (nb[i + 1] != '0') || (nb[i + 2] != '0'))
		{
			if (i != 0)
				ft_putchar(' ');
			print_hundreds(nb[i], nb[i + 1], nb[i + 2], dict); //prints number from 0 to 999
			if (i < len - 3)
			{
				ft_putchar(' ');
				ft_putstr(dict[(len - 1 - i) / 3 + 28]); //prints suffix
			}
		}
		i += 3;
	}
	free_arr(dict, 41, 2); // free dictionary
}
