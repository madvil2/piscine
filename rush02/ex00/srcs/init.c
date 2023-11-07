/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:22:57 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/16 19:10:03 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

char	*save_value(char *str) // function to save only a value without spaces
{
	int		i;
	int		end;
	char	*res;

	while (*str != ':')
		str++;
	str++;
	while (*str == ' ')
		str++;
	end = ft_strlen(str) - 1;
	while (str[end] == ' ')
		end--;
	res = (char *)malloc((end + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < end + 1)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*find_value(char **arr, int key, int flag) // function to save certain entry from an 2d array
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if ((flag == 0 && ft_atoi(arr[i]) == key)
			|| (flag == 1 && is_suff(arr[i], key)))
			return (save_value(arr[i]));
		i++;
	}
	return (NULL);
}

int	is_suff(char *str, int power) // function to check if its a suffix that we looking for
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] != '1')
		return (0);
	i++;
	while (str[i] == '0')
	{
		power--;
		i++;
	}
	if (power == 0 && !(str[i] >= '0' && str[i] <= '9'))
		return (1);
	return (0);
}

char	**dict_create(char **arr)
{
	int		i;
	char	**res;

	if (!arr)
		return (NULL);
	i = -1;
	res = (char **)malloc(41 * sizeof(char *));
	if (!res)
		return (NULL);
	while (++i <= 40)
	{
		if (i <= 20)
			res[i] = find_value(arr, i, 0); // save values from 0 to 20
		else if (i <= 28)
			res[i] = find_value(arr, 20 + (i % 10) * 10, 0); // save values from 30 to 100
		else
			res[i] = find_value(arr, (i - 28) * 3, 1); // save values from 1000 to 1000000000000000000000000000000000000
		if (!(res[i])) //free in case of error
		{
			free_arr(res, i, 0);
			return (free_arr(arr, 420, 1));
		}
	}
	free_arr(arr, 420, 1); // free array from a split
	return (res);
}
