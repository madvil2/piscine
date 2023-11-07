/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:14:24 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 15:32:38 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s1;
	int			i;

	i = 0;
	s1 = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!s1)
		return (NULL);
	while (i < ac)
	{
		s1[i].str = av[i];
		s1[i].copy = ft_strdup(av[i]);
		if (!s1[i].copy)
			return (NULL);
		s1[i].size = ft_strlen(av[i]);
		i++;
	}
	s1[i].str = 0;
	s1[i].copy = 0;
	s1[i].size = 0;
	return (s1);
}
