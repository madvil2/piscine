/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:28:09 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/15 20:28:14 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	error_print(int error) // print errors
{
	if (error == 1)
		write (1, "Error\n", 6);
	if (error == 2)
		write (1, "Dict Error\n", 11);
	return (0);
}

int	ft_strlen(char *str) // calculates the length of a string
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res++;
	return (res);
}

char	*ft_strjoin(char *s1, char *s2) // create a new string from concatenation s1 and s2
{
	char	*res;
	int		i;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (*s1)
			res[i++] = *s1++;
	}
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	return (res);
}

int	fill_zero(char *str, int size) // fill buffer with a '\0'
{
	while (size > 0)
	{
		str[size - 1] = 0;
		size--;
	}
	return (1);
}

int	check_input(char **str) // checking if input string is valid or not
{
	int	i;

	i = 0;
	if (ft_strlen(*str) == 0)
		return (1);
	while (**str == '0')
		(*str)++;
	while ((*str)[i])
	{
		if (!((*str)[i] >= '0' && (*str)[i] <= '9'))
			return (1);
		i++;
	}
	if (ft_strlen(*str) > 39)
		return (2);
	return (0);
}
