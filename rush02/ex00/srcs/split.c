/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:23:11 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/15 20:23:11 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	check_symb(char c, char *sep) // detetmine if character is separator
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	str_count(char *str, char *sep) //counting number of a strings
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!check_symb(str[i], sep) && (i == 0 || check_symb(str[i - 1], sep)))
			res++;
		i++;
	}
	return (res);
}

int	len_count(char *str, char *sep, int n) // count length of n-th string
{
	int	i;
	int	counter;
	int	res;

	i = 0;
	res = 0;
	counter = -1;
	while (str[i])
	{
		if (!check_symb(str[i], sep) && (i == 0 || check_symb(str[i - 1], sep)))
			counter++;
		if (n == counter && !check_symb(str[i], sep))
			res++;
		i++;
	}
	return (res);
}

char	*string_save(char *str, char *sep, int n) // save n-th string
{
	int		i;
	int		j;
	int		counter;
	char	*res;

	i = 0;
	j = 0;
	counter = -1;
	res = (char *)malloc((len_count(str, sep, n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (!check_symb(str[i], sep) && (i == 0 || check_symb(str[i - 1], sep)))
			counter++;
		if (n == counter && !check_symb(str[i], sep))
			res[j++] = str[i];
		i++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset) // split string into 2d array by the separators
{
	char	**res;
	int		size;
	int		i;

	if (!str)
		return (NULL);
	size = str_count(str, charset);
	res = (char **)malloc((size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[size] = 0;
	i = 0;
	while (i < size)
	{
		res[i] = string_save(str, charset, i);
		if (!(res[i]))
		{
			free_arr(res, i, 0);
			free(str);
			return (NULL);
		}
		i++;
	}
	free(str);
	return (res);
}
