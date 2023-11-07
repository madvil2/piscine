/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_check_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:10:32 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 21:26:41 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	check_charset(char *charset, char **str)
{
	int	i;

	i = 0;
	if (ft_strlen(*str) < 3)
		return (0);
	charset[0] = *((*str)++);
	charset[1] = *((*str)++);
	charset[2] = *((*str)++);
	while (i < 3)
	{
		if (charset[i] < 32 || charset[i] > 126)
			return (0);
		i++;
	}
	if (charset[0] == charset[1] || charset[1] == charset[2]
		|| charset[0] == charset[2])
		return (0);
	return (1);
}

int	check_lines_count(char **str)
{
	long	res;

	res = 0;
	while (**str >= '0' && **str <= '9')
	{
		res = res * 10 + **str - 48;
		if (res > 2147483647)
			return (0);
		(*str)++;
	}
	return ((int)res);
}

int	check_rows(char **str, t_bsq *data)
{
	int	count_x;
	int	count_y;
	int	i;

	i = 0;
	count_x = 0;
	count_y = 0;
	while ((*str)[i] != '\0')
	{
		while ((*str)[i] != '\n')
		{
			if ((*str)[i] != data->charset[0] && (*str)[i] != data->charset[1])
				return (0);
			count_x++;
			i++;
		}
		count_y++;
		if (data->x == 0 || count_x != data->x)
			return (0);
		count_x = 0;
		i++;
	}
	if (count_y != data->y)
		return (0);
	return (1);
}

int	check_input(char **str, t_bsq *data)
{
	int	i;

	i = 0;
	if (str[0])
	{
		data->save = *str;
		data->max = -1;
		data->y = check_lines_count(str);
		if (data->y == 0)
			return (0);
		if (!check_charset(data->charset, str))
			return (0);
		if (*((*str)++) != '\n')
			return (0);
		while ((*str)[i] && (*str)[i] != '\n')
			i++;
		data->x = i;
		if (!check_rows(str, data))
			return (0);
		return (1);
	}
	return (0);
}
